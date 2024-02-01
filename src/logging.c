// should be logged in this format:
//	<Timestamp-LogLevel-Source-Message(result)-StackTrace>
//------------------------------------------------------------
//                      declarations
//------------------------------------------------------------



#include "config.h"
// declarations included in config.h(main header)

#define DEBUG_OUTPUT 0
#define MAX_LEN 1000
#define MAX_LINES 100

// default value when you start using the machine
bool machine_mode = true;



//-------------------------------------------------------------------------
//these were in the header file but due to some bugs i moved them here , Ahmd
enum Level {
    INFO, // 0
    WARNING, // 1                               
    ERROR, //2
	MACHINE_CHANGE_MODE // 3
};

enum Level level_number(int _lvl) {
    return _lvl;
};

struct LogStruct {//arguments of writing
    char _date[SIZE];
    char _time[SIZE];
    char _file_name[SIZE];
    char _stage[SIZE];
    char _input[SIZE];
    char _output[SIZE];
    enum Level _level;
};
//-------------------------------------------------------------------------


// should  be defined globaly
char r1[26] = {'C', 'X', 'F', 'G', 'E', 'V', 'A', 'H', 'N', 'M', 'B', 'D', 'L', 'K', 'P', 'O', 'Z', 'T', 'Q', 'J', 'I', 'W', 'S', 'R', 'U', 'Y'};
char r2[26] = {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'};
char r3[26] = {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'};
char r4[26] = {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'};
char r5[26] = {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'};


// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                       Internal Functions
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

/*
/* NOTE: Internal function!
/* @dev Not useable for outside of this file.
/* @param input takes Enigma machine input
/* @param output takes Enigma machine output
/* @returns enum Level value. 
/* @notice this check project setup safety, for this purpose, the function
	could be extended in newly difference aspects of project safety.
	you could override this function BTW.
*/
enum Level _project_status_check(char *input, char *output) {
	// check project workflow safety
	int log_status_number = 0; // INFO as default

	//This was a bug so the team decided to remove it
	// ERROR status:
	//if (strcmp(input, output) == 0) {
		//printf("\x1b[41m Input and output for plugboard are both same, There is no change in the Enigma algorithm\x1b[0m\n");
		// log_status_number = 2;
	//}

	// ERROR status
	if ((input == NULL) || (output == NULL)) {
		printf("\x1b[41m value of input or output is not valid!\n");
		log_status_number = 2;
	}

	
    //--------------------------------------------------important
	// checking logs directory
    // for this section we need to run this solution on a linux based system
	// in windows we dont have the libraries!!! in these check for erors in the 
	// log folder so we can comment them 
    //--------------------------------------------------important



	// DIR *directory;
	// struct dirent *entry;

	// directory = opendir("../logs");

	// if (directory == NULL) {
	// 	printf("\x1b[41m There is not any log directory\n");
	// 	log_status_number = 2;
	// 	return log_status_number;
	// } else {
	// 	while((entry = readdir(directory)) != NULL) {
	// 		if (entry->d_type == DT_REG) {
	// 			if(strcmp(entry->d_name, "machine_logs.log") != 0) {
	// 				log_status_number = 1;
	// 				printf("\x1b[41m There is another file exists in the /log folder\n");
	// 			}
	// 		}

	// 		if ((entry->d_type == DT_DIR)
	// 				&& (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)) 
	// 		{
	// 			log_status_number = 1;
	// 			printf("\x1b[41m There is an uknown folder in the /log directory\n");
	// 		}
	// 	}
	// }

	return level_number(log_status_number);
}



/*
/* NOTE: Internal function!
/* @dev Not useable for outside of this file.
/* @param input takes Enigma machine input
/* @param output takes Enigma machine output
/* @param stage which is the stage that we are in during the machine encryption workflow.
/* @returns log_data struct which contains log status value based on the LogStruct structure.
/* @notice this function will use in `logging` and `change_mode` function to
	generate the Enigma machine each stage I/O status based on the `LogStruct` structure.
*/
struct LogStruct _log_status_generator(char *input, char *output, char *stage) {
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

	int project_status_number = _project_status_check(input, output);
	log_data._level = project_status_number;

	return log_data;
}


/*
/* NOTE: Internal function!
/* @dev Not useable for the outside of this file.
/* @param _log which is the machine log structure that generated from the `_log_status_generator` function.
/* @param _status_code is the enum Level status of the log to generate proportional log format.
	which is loosely based on the official log reporting in most systems.
/* returns a formatted string based on this pattern => <DATE>-<TIME>-<FILE>-<STAGE>-<INPUT>-<OUTPUT>
/* @notice The log of `_formatter` function is based on the _status_code that we are giving to it.
	If the (_status_code -> 0) then the log is on the INFO status.
	If the (_status_code -> 1) then the log is on the WARNING status.
	If the (_status_code -> 2) then the log is on the ERROR status which if this status occured, the function will exit via ExitCode=1.
	If the (_status_code -> 3) is the `START / END` status of the machine workflow.
		this status code will come up once before runninng the machine and once after ending the machine encryption process. 
		this status code will occur if we call the `change_mode` function.
/*
*/
char* _formatter(struct LogStruct _log, enum Level _status_code) {
	char *data_formatted = (char*)malloc(BUFFER_SIZE * sizeof(char));

	switch(_status_code) {
		case 0: // in INFO log level
			sprintf(data_formatted, "[INFO]--%s--%s--%s--%s--%s\n",
				_log._time, _log._file_name, _log._stage, _log._input, _log._output
			);

			#ifdef DEBUG_OUTPUT
			printf("\x1b[32m%s", data_formatted);
			#endif
			break;

		case 1: // WARNING log level
			sprintf(data_formatted, "[WARNING]--%s--%s--%s--%s--%s\n",
				_log._time, _log._file_name, _log._stage, _log._input, _log._output
			);
			#ifdef DEBUG_OUTPUT
			printf("x1b[33m%s", data_formatted);
			#endif
			break;

		case 2: // ERROR log level
			sprintf(data_formatted, "[ERROR]--%s--%s--%s--%s--%s\n",
				_log._time, _log._file_name, _log._stage, _log._input, _log._output
			);
			#ifdef DEBUG_OUTPUT
			printf("\x1b[31m%s", data_formatted);
			#endif
			break;

		case 3: //machine mode status switching
			if(machine_mode) {
				sprintf(data_formatted, "[START]--%s--%s--%s--%s--%s\n",
					_log._time, _log._file_name, _log._stage, _log._input, _log._output
				);

				#ifdef DEBUG_OUTPUT
				printf("\n\x1b[38;5;78m%s\n", data_formatted);
				#endif
			} else {
				sprintf(data_formatted, "[END]--%s--%s--%s--%s--%s\n",
					_log._time, _log._file_name, _log._stage, _log._input, _log._output
				);

				#ifdef DEBUG_OUTPUT
				printf("\n\x1b[38;5;203m%s\n", data_formatted);
				#endif
			}
	};

	return data_formatted; // we'll give this to the getLevel function
}

/*
/* NOTE: Internal function!
/* @dev Not useable for the outside of this file.
/* @param _formatted_data is a string the generated from the `formatter` function.
/* @returns nothing and just modify the file inside `/log/machine_log.log` file in append mode.
*/
void _writeLog(char *_formatted_data) {
	FILE *log_file;

	// opening file in append format
	log_file = fopen("../logs/machine_logs.log", "a");

	if (log_file == NULL) {
		printf("\x1b[41m The file doesn't exists in the log folder!\n");
		exit(1);
	} else fputs(_formatted_data, log_file);

	fclose(log_file);
}


static int _get_line_count() {
	FILE *fp;
	int count;
	char c;

	if ((fp = fopen("../logs/machine_logs.log", "r")) != NULL) {
		while (!feof(fp) && !ferror(fp) && c != EOF) {
			c = fgetc(fp);
			if(c == '\n') count ++;
		}
		fclose(fp);
		return count;
	}

	fclose(fp);
	printf("\x1b[31mSome error occured during machine_logs file opening!\n");
	exit(1);
}



unsigned int _indexOF(char c, char arr[])
{
    for (unsigned int i = 0; i < 26; i++)
    {
        if (arr[i] == c)
            return i;
    }
}



// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                       Useable Functions
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

/*
/* NOTE: This is the only function to modify the machine_mode global variable.
/* NOTE: Useable and vital function!
/* @dev use this function during your app to have a logging journy.
/* @param last_input takes Enigma machine input
/* @param last_output takes Enigma machine output
/* @returns Nothing and will change the machine_mode` global variable.
/* @notice This function should only use once before machine start and once after machine close.
	this function is precisely based on the Pauseable system design pattern.
*/
void change_mode(char *last_input, char *last_output) {
	char last_stage[SIZE] = "Plugin"; // known as last stage

	struct LogStruct log_data;
	log_data = _log_status_generator(last_input, last_output, last_stage);

	int format_status = level_number(3);

	char *extracted_data;
    // replace and mark the last log to the config
    // when it wants to be turned off

    if(machine_mode) {
    	extracted_data = _formatter(log_data, format_status);
    	_writeLog(extracted_data);
    	machine_mode = !machine_mode;
    } else {
    	extracted_data = _formatter(log_data, format_status);
    	_writeLog(extracted_data);
    	machine_mode = !machine_mode;
    }

    // bool end_flag = !machine_mode;
    // void* machine_mode = &end_flag;
    // printf("test\n");
    
}

/*
/* NOTE: This is the only function to modify the machine_mode global variable.
/* NOTE: Useable and vital function!
/* @dev use this function during your app to have a logging journy.
/* @param input takes Enigma machine input
/* @param output takes Enigma machine output
/* @param stage which is the machine stage level that you are in.
/* @returns Nothing and log the formatted data into the `/log/machine_log.log` file.
/* @dev if the DEBUG_OUTPUT was 0 the formatted log data will either print simultenuosly beside of the `machine_log.log` file.  
*/
void logging(char *input, char *output, char *stage) {
	struct LogStruct log_data;
	log_data = _log_status_generator(input, output, stage);

	if (log_data._level == 2) 
		exit(1);
	else {
		char *extracted_data = _formatter(log_data, log_data._level);

		_writeLog(extracted_data);
	}
}



// related to the get_log_config function
struct LastModifyConfig {
	unsigned int last_R1;
	unsigned int last_R2;
	unsigned int last_R3;
};


#define LAST_R1 ((_get_line_count()))
#define LAST_R2 ((_get_line_count())-1)
#define LAST_R3 ((_get_line_count())-2)
#define LAST_CHAR_IDX 52
/*
/* NOTE: Useable and vital function!
/* @dev This function could be used before running the Enigma Machine to set the prepotional Rotors position.
/* @returns a LastModifyConfig struct which is the config that you have to set before running the Enigma Machine.
*/
static struct LastModifyConfig get_log_config() {
	struct LastModifyConfig _config;

	FILE *fp;

	int read_line = _get_line_count();

	//printf("%d %d %d\n", LAST_R1, LAST_R2, LAST_R3);

	if((fp = fopen("../logs/machine_logs.log", "r")) != NULL) {
		int line = 1;
		
		char data_in_file[MAX_LINES][MAX_LEN];

		while(!feof(fp) && !ferror(fp)) {

			if(fgets(data_in_file[line], MAX_LEN, fp) != NULL) {
				if (line == LAST_R1) _config.last_R1 = _indexOF(
					data_in_file[line][LAST_CHAR_IDX], r1);

				else if(line == LAST_R2) _config.last_R2 = _indexOF(
					data_in_file[line][LAST_CHAR_IDX], r2);

				else if (line == LAST_R3) _config.last_R3 = _indexOF(
					data_in_file[line][LAST_CHAR_IDX], r3);

				line ++;
			}
		}
	}
	fclose(fp);
	return _config;
}

// NOTE: this main should be deleted.
// int main() {
// 	struct LastModifyConfig conf;
// 	conf = get_log_config();
// 	printf("%u %u %u\n", conf.last_R1, conf.last_R2, conf.last_R3);
// }






// NOTE: This is just a sample of the logging.c workflow and should be deleted in the production phase.
// int main() {
// 	// sample input
// 	change_mode("X", "Z"); // turn on

// 	logging("A", "B", "R1");
// 	logging("B", "C", "R2");
// 	logging("C", "D", "R3");
// 	logging("D", "E", "REF");
// 	logging("E", "F", "R3");
// 	logging("F", "G", "R2");
// 	logging("G", "H", "R1");

// 	change_mode("H", "I"); // turn off
// /////////////////////////////////////////////// SECOND ROUND
// 	change_mode("X", "Z"); // turn on

// 	logging("A", "B", "R1");
// 	logging("B", "C", "R2");
// 	logging("C", "D", "R3");
// 	logging("D", "E", "REF");
// 	logging("E", "F", "R3");
// 	logging("F", "G", "R2");
// 	logging("G", "H", "R1");

// 	change_mode("H", "I"); // turn off

// 	int n = _get_line_count();
// 	printf("%d\n", n);
// 	return 0;
// }
