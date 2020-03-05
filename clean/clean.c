#define SUCCESS 0
#define FAILURE 1

#include <stdio.h>
#include <string.h>

#include "./calculations.c"
#include "./printing.c"

typedef struct  {
    char *pBuffer;
    short buffer_size;
    short numeric_representation;
    short length;
} userInput_type;

// ========================================
// Function Prototypes
// ========================================

int get_user_body_height_cm();
int read_user_input(userInput_type *);
int validate_string_contains_only_figures(userInput_type *);
int convert_string_of_figures_to_number(userInput_type*);

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
    userInput_type user_input;
    const char buffer_size  = 5;
    char input_buffer[buffer_size];
    user_input.pBuffer      = input_buffer;
    user_input.buffer_size  = buffer_size;
    user_input.length       = 0;
    user_input.pBuffer[0]   = '\0';

    do {
        printf("Your body height in cm: ");
        read_user_input(&user_input);
    } while (validate_string_contains_only_figures(&user_input) != SUCCESS);

    user_input.numeric_representation = convert_string_of_figures_to_number(&user_input);
    return user_input.numeric_representation;
}

int read_user_input(userInput_type* input) {
    short userInputValid  = 0;
    char  input_char      = '\0';
    char *pInput_buffer   = input->pBuffer;

    input->length = 0;
    while ((input_char = getchar()) != '\n')
    {
        *pInput_buffer++ = input_char;
        input->length++;

        if (input->length >= input->buffer_size - 1)
        {
            break;
        }
    }
    *pInput_buffer = '\0';

    return SUCCESS;
}

int validate_string_contains_only_figures(userInput_type* input) {
    char *input_buffer = input->pBuffer;

    for (int i = 0; i < input->length; input_buffer++, i++) {
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

int convert_string_of_figures_to_number(userInput_type* input) {
    short char_processed_count = 0;
    int   number               = 0;
    char* input_buffer         = input->pBuffer;

    for (int i = 0; i < input->length; input_buffer++, i++) {
        if (*input_buffer == '\0') {
            break;
        } else {
            number = 10 * number + (*input_buffer - '0');
        }
    }

    return number;
}
