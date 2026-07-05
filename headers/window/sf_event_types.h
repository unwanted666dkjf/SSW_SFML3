#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_TYPES_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_TYPES_H


#ifdef __cplusplus
extern "C" {
#endif


// Unkown event
#define SFML_SIMPLE_WRAPPER_sf_Event_Unknown (-1)

// Event type: closed
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_Closed 0

// Event type: resized
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_Resized 1

// Event type: lost focus
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_LostFocus 2

// Event type: gained focus
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_GainedFocus 3

// Event type: text entered
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_TextEntered 4

// Event type: key pressed
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_KeyPressed 5

// Event type: key released
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_KeyReleased 6

// Event type: mouse wheel moved
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseWheelMoved 7

// Event type: mouse wheel scrolled
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseWheelScrolled 8

// Event type: mouse button pressed
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseButtonPressed 9

// Event type: mouse button released
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseButtonReleased 10

// Event type: mouse moved
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseMoved 11

// Event type: mouse entered
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseEntered 12

// Event type: mouse left
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseLeft 13

// Event type: joystick button pressed
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_JoystickButtonPressed 14

// Event type: joystick button released
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_JoystickButtonReleased 15

// Event type: joystick moved
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_JoystickMoved 16

// Event type: joystick connected
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_JoystickConnected 17

// Event type: joystick disconnected
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_JoystickDisconnected 18

// Event type: touch began
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_TouchBegan 19

// Event type: touch moved
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_TouchMoved 20

// Event type: touch ended
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_TouchEnded 21

// Event type: sensor changed
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_SensorChanged 22

// Event type count (Old, from SFML2)
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_Count 23

// Event type: raw mouse moved (May not be equal to the real one)
#define SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseMovedRaw 24


#ifdef __cplusplus
}
#endif


#endif
