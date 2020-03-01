#include <stdio.h>
#include <string.h>

#include "./calculations.c"
#include "./printing.c"

// ========================================
// Function Prototypes
// ========================================
int get_user_body_height_cm();
int read_user_input(char* input_buffer, short buffer_size);
int validate_string_contains_only_figures(char* input_buffer, short buffer_size);
int convert_string_of_figures_to_number(char* input_buffer, short buffer_size);

// ========================================
// Functions
// ========================================
int main(void) {
    int   body_height_cm      = get_user_body_height_cm();
    int   eye_height_cm       = calculate_users_height_of_eyes(body_height_cm);
    float horizon_distance_km = calculate_horizon_distance_km(eye_height_cm);
    print_horizon_distance(horizon_distance_km);
    return 0;
}

int get_user_body_height_cm() {
    const char buffer_size = 5;
    char       input_buffer[buffer_size];
    short      userInputValid;
    short      inputLength;

    do {
        printf("Your body height in cm: ");
        inputLength = read_user_input(input_buffer, buffer_size);
        userInputValid =
            validate_string_contains_only_figures(input_buffer, inputLength);
    } while (!userInputValid);
    return convert_string_of_figures_to_number(input_buffer, inputLength);
}

int read_user_input(char* input_buffer, short buffer_size) {
    char  input_char;
    short char_read_count = 0;
    const short return_key      = 13;

    while ((input_char = getchar()) != '\n') {
        *input_buffer++ = input_char;
        char_read_count++;
        if (char_read_count >= buffer_size - 1) {
            break;
        }
    }
    *input_buffer = '\0';
    return char_read_count;
}

int validate_string_contains_only_figures(char* input_buffer,
                                          short buffer_size) {
    for (int i = 0; i < buffer_size; input_buffer++, i++) {
        short charIsNoFigure = (*input_buffer > '9') || (*input_buffer < '0');
        if (charIsNoFigure) {
            return 0;
        }
        if (*input_buffer == '\0') {
            break;
        }
    }
    return 1;
}

int convert_string_of_figures_to_number(char* input_buffer, short buffer_size) {
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
