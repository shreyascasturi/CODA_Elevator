#include <stdio.h>
#include <unistd.h>

// what should elevator implementation do?

// be able to spawn up a gui that shows
// an elevator with multiple floors.
// A user should be able to say what floor they want to go to
// and the user should be able to go to that floor.

// what do you need?
// I need ability to take in input (only what floor I want to go to,
// do bounds checking).

// Assumptions: Assume 10 floors for now. 
// Assume elevator starts on 1st floor.
// Assume you can go up and down like usual.

int current_floor;
int num_of_floors;
int go_up;
int go_down;
int char_constant;

int elevator_execute();

int main() 
{
    
    printf("---- Instantiating Elevator ----\n");
    elevator_execute();
    printf("---- Thanks for using elevator ----\n");
    return 1;

}

int elevator_execute() 
{
    extern int current_floor;
    extern int num_of_floors;
    extern int go_up;
    extern int go_down;
    extern int char_constant;
    current_floor = 1;
    num_of_floors = 10;
    go_up = 0;
    go_down = 0;
    char_constant = 48;
    while(1) {
        printf("---- Current Floor: %d ----\n", current_floor);
        printf("What floor would you like to go to: ");

        printf("\n\n");
        int floor_to_go = getchar() - 48;

        printf("floor choice: %d\n", floor_to_go);

        while (floor_to_go > num_of_floors || (floor_to_go < 0 && floor_to_go != -1)) {
            printf("---- Unable to service this floor! ----\n");
            printf("---- enter another floor ----\n");
            floor_to_go = getchar();
        }
        if (floor_to_go == -1) {
            printf("---- Exiting elevator system ---- ");
            return 1;
        }
        int difference_between_floor = floor_to_go - current_floor;        
        go_up = difference_between_floor >= 0 ? 1 : 0;
        go_down = difference_between_floor < 0 ? 1 : 0;
        printf("---- Going to the %d-th floor ----\n", floor_to_go);
        sleep(.5);
        current_floor = floor_to_go;
    }
    
}
