// should be logged in this format:
//	<Timestamp-LogLevel-Source-Message(result)-StackTrace>

#include "config.h"
// declarations included in config.h(main header)


enum Level project_status_check(char *input, char *output) {
	// check project workflow safety
	int log_status_number = 0; // INFO as default

	// ERROR status:
	if (strcmp(input, output) == 0) {
		printf("\x1b[41m Input and output are both same, some error occurred in the Enigma algorithm\n");
		log_status_number = 2;
	}

	// ERROR status
	if ((input == NULL) || (output == NULL)) {
		printf("\x1b[41m value of input or output is not valid!\n");
		log_status_number = 2;
	}


	// checking logs directory
	DIR *directory;
	struct dirent *entry;

	directory = opendir("../logs");

	if (directory == NULL) {
		printf("\x1b[41m There is not any log directory\n");
		log_status_number = 2;
		return log_status_number;
	} else {
		while((entry = readdir(directory)) != NULL) {
			if (entry->d_type == DT_REG) {
				if(strcmp(entry->d_name, "machine_logs.log") != 0) {
					log_status_number = 1;
					printf("\x1b[41m There is another file exists in the /log folder\n");
				}
			}

			if ((entry->d_type == DT_DIR) 
					&& (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)) 
			{
				log_status_number = 1;
				printf("\x1b[41m There is an uknown folder in the /log directory\n");
			}
		}
	}

	return level_number(log_status_number);
}


#define DEBUG_OUTPUT 0
// Format -> <DATE>-<TIME>-<FILE>-<STAGE>-<INPUT>-<OUTPUT>
char* formatter(struct LogStruct _log, enum Level _status_code) {
	char *data_formatted = (char*)malloc(BUFFER_SIZE * sizeof(char));

	switch(_status_code) {
		case 0: // in INFO log level
			sprintf(data_formatted, "\x1b[32m [INFO]--%s--%s--%s--%s--%s\n",
				_log._time, _log._file_name, _log._stage, _log._input, _log._output
			);

			#ifdef DEBUG_OUTPUT
			printf("%s\n", data_formatted);
			#endif
			break;

		case 1: // WARNING log level
			sprintf(data_formatted, "\x1b[33m [WARNING]--%s--%s--%s--%s--%s",
				_log._time, _log._file_name, _log._stage, _log._input, _log._output
			);
			#ifdef DEBUG_OUTPUT
			printf("%s\n", data_formatted);
			#endif
			break;

		case 2: // ERROR log level
			sprintf(data_formatted, "\x1b[31m [ERROR]--%s--%s--%s--%s--%s",
				_log._time, _log._file_name, _log._stage, _log._input, _log._output
			);
			#ifdef DEBUG_OUTPUT
			printf("%s\n", data_formatted);
			#endif
			break;
	};

	return data_formatted; // we'll give this to the getLevel function
}


void writeLog(char *_formatted_data) {
	FILE *log_file;

	// opening file in append format
	log_file = fopen("../logs/machine_logs.log", "a");

	if (log_file == NULL) {
		printf("\x1b[41m The file doesn't exists in the log folder!\n");
		exit(1);
	} else fputs(_formatted_data, log_file);

	fclose(log_file);
}


// The main function that you should call to use this file
#define SIZE 101
#define DEBUG_OUTPUT 0
void logging(char *input, char *output, char *stage) {
	struct LogStruct log_data;

	time_t t;
	time(&t);
	char* TIME = ctime(&t);
	TIME[strlen(TIME)-1] = '\0';
	const char FILENAME[SIZE] = __FILE__;

	strcpy(log_data._time, TIME);
	strcpy(log_data._file_name, FILENAME);
	strcpy(log_data._stage, stage);
	strcpy(log_data._input, input);
	strcpy(log_data._output, output);

	int project_status_number = project_status_check(input, output);
	log_data._level = project_status_number;

	if (project_status_number == 2) 
		exit(1);
	else {
		char *extracted_data = formatter(log_data, project_status_number);

		writeLog(extracted_data);
	}
}


int main() {
	// sample input
	logging("A", "B", "R1");
	return 0;
}
