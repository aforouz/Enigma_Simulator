#include "config.h"

bool machine_mode = false;

void change_mode() {
    // replace and mark the last log to the config

    // change global machine_mode to true.
    machine_mode = machine_mode ? false : true; // means it's turned off.
    // void* machine_mode = &end_flag;
    // printf("test\n");
    return;
}

int main() {
	printf("%d\n", machine_mode);
	change_mode();
	printf("%d\n", machine_mode);

	return 0;
}
