#include <math.h>
#include <stdio.h>
#include <string.h>

// ========================================
//  F U N C T I O N   P R O T O T Y P E S =
// ========================================
int  get_user_body_height_cm();
int read_user_input(char* input_buffer, short buffer_size);
int  validate_string_contains_only_figures(char* input_buffer,
                                           short buffer_size);
int  convert_string_of_figures_to_number(char* input_buffer, short buffer_size);
int  calculate_users_height_of_eyes(int body_height_cm);
float calculate_horizon_distance_km(int view_height_cm);
float calculate_triangle_angle_from_adjacent_and_hypothenuse(
    float adjacent_length, float hypothenuse_length);
float calculate_distance_circle_segment(float radius, float angle);
void  print_horizon_distance(float distance);

// ========================================
//  F U N C T I O N S                     =
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

int calculate_users_height_of_eyes(int body_height_cm) {
    return body_height_cm - 10;
}

float calculate_horizon_distance_km(int view_height_cm) {
    int   earth_radius_km = 6371;
    int   earth_radius_cm = earth_radius_km * 100000;
    float angle;

    angle = calculate_triangle_angle_from_adjacent_and_hypothenuse(
        earth_radius_cm, earth_radius_cm + view_height_cm);
    return calculate_distance_circle_segment(earth_radius_km, angle);
}

float calculate_triangle_angle_from_adjacent_and_hypothenuse(
    float adjacent_length, float hypothenuse_length) {
    return acos(adjacent_length / hypothenuse_length);
}

float calculate_distance_circle_segment(float radius, float angle) {
    return radius * angle;
}

void print_horizon_distance(float distance) {
    printf("\nThe horizon on a calm ocean is %.2f km far away.\n", distance);
}
