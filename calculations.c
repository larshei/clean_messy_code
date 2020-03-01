#include <math.h>

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
