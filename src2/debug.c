#include "config.h"
#include <json-c/json.h>  

//// TEST FILE, IT'S NOT USEABLE ////

bool machine_mode = false;

void change_mode() {
    // replace and mark the last log to the config

    // change global machine_mode to true.
    machine_mode = machine_mode ? false : true; // means it's turned off.
    // void* machine_mode = &end_flag;
    // printf("test\n");
    return;
}

// int main() {
// 	printf("%d\n", machine_mode);
// 	change_mode();
// 	printf("%d\n", machine_mode);

// 	return 0;
// }

int main(int argc, char **argv) {
    FILE *fp;
    char buffer[SIZE];

    struct json_object *parsed_json;
    struct json_object *username;
    struct json_object *password;

    fp = fopen("../encrypted_data/data.json", "r");
    fread(buffer, SIZE, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "username", &username);
    json_object_object_get_ex(parsed_json, "password", &password);

    printf("%s\n", json_object_get_string(username));

    return 0;
}