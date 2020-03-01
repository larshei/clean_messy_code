#define SUCCESS 0
#define FAILURE 1

#include <stdio.h>
#include <string.h>

#include "./calculations.c"
#include "./printing.c"

struct InputString {
    char *value,
    short numeric_representation,
    short length,
}

// ========================================
// Function Prototypes
// ========================================
int get_user_body_height_cm();
int read_user_input(InputString);
int validate_string_contains_only_figures(InputString);
int convert_string_of_figures_to_number(InputString);

// ========================================
// Functions
// ========================================
int main(void) {
    int   body_height_cm      = get_user_body_height_cm();
    int   eye_height_cm       = calculate_users_height_of_eyes(body_height_cm);
    float horizon_distance_km = calculate_horizon_distance_km(eye_height_cm);

    print_horizon_distance(horizon_distance_km);

    return SUCCESS;
}

int get_user_body_height_cm() {
    InputString user_input;

    printf("Your body height in cm: ");
    user_input = read_user_input();

    user_input.numeric_representation = convert_string_of_figures_to_number(user_input);

    return user_input;
}

int read_user_input(InputString input) {
    short      userInputValid  = 0;
    short      inputLength     = 0;
    char       input_char      = '\0';
    short      char_read_count = 0;
    const char buffer_size     = 5;
    char       input_buffer[buffer_size];

    do {
        while ((input_char = getchar()) != '\n') {
            *input_buffer++ = input_char;
            char_read_count++;

            if (char_read_count >= buffer_size - 1) {
                break;
            }
        }

        user_input = read_user_input(input_buffer, buffer_size);
        userInputValid = validate_string_contains_only_figures(input_buffer, inputLength);
    } while (!userInputValid);

    *input_buffer = '\0';

    return char_read_count;
}

int validate_string_contains_only_figures(InputString input) {

    for (int i = 0; i < buffer_size; input_buffer++, i++) {
        int charIsNoFigure = (*input_buffer > '9') || (*input_buffer < '0');
        if (charIsNoFigure) {
            return FAILURE;
        }
        if (*input_buffer == '\0') {
            break;
        }
    }

    return SUCCESS;
}

int convert_string_of_figures_to_number(InputString input) {
    short char_processed_count = 0;
    int   number               = 0;

    for (int i = 0; i < buffer_size; input_buffer++, i++) {
        if (*input_buffer == '\0') {
            break;
        } else {
            number = 10 * number + (*input_buffer - '0');
        }
    }

    return number;
}
