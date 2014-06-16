/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Mega 2560 HAL (Apm 2), Platform=avr, Package=apm
*/

#define __AVR_ATmega2560__
#define ARDUINO 101
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define CONFIG_HAL_BOARD HAL_BOARD_APM2
#define EXCLUDECORE
#define __cplusplus
extern "C" void __cxa_pure_virtual() {;}

AP_Pixy getPixy();
AP_Pixy getPixy();
//
static void compass_accumulate(void);
static void barometer_accumulate(void);
static void perf_update(void);
//
static void fast_loop();
static void rc_loop();
static void throttle_loop();
static void update_mount();
static void update_batt_compass(void);
static void ten_hz_logging_loop();
static void fifty_hz_logging_loop();
static void three_hz_loop();
static void one_hz_loop();
static void update_optical_flow(void);
static void update_GPS(void);
static void init_simple_bearing();
void update_simple_mode(void);
void update_super_simple_bearing(bool force_update);
static void read_AHRS(void);
static void update_altitude();
static void tuning();
void set_home_is_set(bool b);
void set_auto_armed(bool b);
void set_simple_mode(uint8_t b);
static void set_failsafe_radio(bool b);
void set_failsafe_battery(bool b);
static void set_failsafe_gps(bool b);
static void set_failsafe_gcs(bool b);
void set_land_complete(bool b);
void set_pre_arm_check(bool b);
void set_pre_arm_rc_check(bool b);
float get_smoothing_gain();
static void get_pilot_desired_lean_angles(int16_t roll_in, int16_t pitch_in, int16_t &roll_out, int16_t &pitch_out);
static float get_pilot_desired_yaw_rate(int16_t stick_angle);
static float get_roi_yaw();
static float get_look_ahead_yaw();
static void update_thr_cruise();
static void set_throttle_takeoff();
static int16_t get_pilot_desired_throttle(int16_t throttle_control);
static int16_t get_pilot_desired_climb_rate(int16_t throttle_control);
static float get_throttle_surface_tracking(int16_t target_rate, float current_alt_target, float dt);
static void set_accel_throttle_I_from_pilot_throttle(int16_t pilot_throttle);
static void gcs_send_heartbeat(void);
static void gcs_send_deferred(void);
static NOINLINE void send_heartbeat(mavlink_channel_t chan);
static NOINLINE void send_attitude(mavlink_channel_t chan);
static NOINLINE void send_limits_status(mavlink_channel_t chan);
static NOINLINE void send_extended_status1(mavlink_channel_t chan);
static void NOINLINE send_location(mavlink_channel_t chan);
static void NOINLINE send_nav_controller_output(mavlink_channel_t chan);
static void NOINLINE send_ahrs(mavlink_channel_t chan);
static void NOINLINE send_simstate(mavlink_channel_t chan);
static void NOINLINE send_hwstatus(mavlink_channel_t chan);
static void NOINLINE send_gps_raw(mavlink_channel_t chan);
static void NOINLINE send_system_time(mavlink_channel_t chan);
static void NOINLINE send_servo_out(mavlink_channel_t chan);
static void NOINLINE send_radio_in(mavlink_channel_t chan);
static void NOINLINE send_radio_out(mavlink_channel_t chan);
static void NOINLINE send_vfr_hud(mavlink_channel_t chan);
static void NOINLINE send_raw_imu1(mavlink_channel_t chan);
static void NOINLINE send_raw_imu2(mavlink_channel_t chan);
static void NOINLINE send_raw_imu3(mavlink_channel_t chan);
static void NOINLINE send_current_waypoint(mavlink_channel_t chan);
static void NOINLINE send_rangefinder(mavlink_channel_t chan);
static void NOINLINE send_statustext(mavlink_channel_t chan);
static bool telemetry_delayed(mavlink_channel_t chan);
static void mavlink_delay_cb();
static void gcs_send_message(enum ap_message id);
static void gcs_data_stream_send(void);
static void gcs_check_input(void);
static void gcs_send_text_P(gcs_severity severity, const prog_char_t *str);
static bool print_log_menu(void);
static void do_erase_logs(void);
static void Log_Write_AutoTune(uint8_t axis, uint8_t tune_step, float rate_min, float rate_max, float new_gain_rp, float new_gain_rd, float new_gain_sp);
static void Log_Write_AutoTuneDetails(int16_t angle_cd, float rate_cds);
static void Log_Write_Current();
static void Log_Write_Optflow();
static void Log_Write_Nav_Tuning();
static void Log_Write_Control_Tuning();
static void Log_Write_Compass();
static void Log_Write_Performance();
static void Log_Write_Attitude();
static void Log_Write_Mode(uint8_t mode);
static void Log_Write_Startup();
static void Log_Write_Event(uint8_t id);
static void Log_Write_Data(uint8_t id, int16_t value);
static void Log_Write_Data(uint8_t id, uint16_t value);
static void Log_Write_Data(uint8_t id, int32_t value);
static void Log_Write_Data(uint8_t id, uint32_t value);
static void Log_Write_Data(uint8_t id, float value);
static void Log_Write_Camera();
static void Log_Write_Error(uint8_t sub_system, uint8_t error_code);
static void Log_Write_Baro(void);
static void Log_Read(uint16_t log_num, uint16_t start_page, uint16_t end_page);
static void start_logging();
static void Log_Write_Startup();
static void Log_Write_Mode(uint8_t mode);
static void Log_Write_IMU();
static void Log_Write_AutoTune(uint8_t axis, uint8_t tune_step, float rate_min, float rate_max, float new_gain_rp, float new_gain_rd, float new_gain_sp);
static void Log_Write_AutoTuneDetails(int16_t angle_cd, float rate_cds);
static void Log_Write_Current();
static void Log_Write_Compass();
static void Log_Write_Attitude();
static void Log_Write_Data(uint8_t id, int16_t value);
static void Log_Write_Data(uint8_t id, uint16_t value);
static void Log_Write_Data(uint8_t id, int32_t value);
static void Log_Write_Data(uint8_t id, uint32_t value);
static void Log_Write_Data(uint8_t id, float value);
static void Log_Write_Event(uint8_t id);
static void Log_Write_Optflow();
static void Log_Write_Nav_Tuning();
static void Log_Write_Control_Tuning();
static void Log_Write_Performance();
static void Log_Write_Camera();
static void Log_Write_Error(uint8_t sub_system, uint8_t error_code);
static void Log_Write_Baro(void);
static void load_parameters(void);
uint16_t assembleWord(uint8_t lowByte, uint8_t highByte);
void userhook_init();
void userhook_FastLoop();
void userhook_50Hz();
void userhook_MediumLoop();
void userhook_SlowLoop();
void userhook_SuperSlowLoop();
static void init_home();
static void exit_mission();
static void do_RTL(void);
static bool verify_takeoff();
static bool verify_land();
static bool verify_loiter_unlimited();
static bool verify_loiter_time();
static bool verify_RTL();
static bool verify_wait_delay();
static bool verify_change_alt();
static bool verify_within_distance();
static bool verify_yaw();
static void do_take_picture();
static uint8_t mavlink_compassmot(mavlink_channel_t chan);
static void delay(uint32_t ms);
static void mavlink_delay(uint32_t ms);
static uint32_t millis();
static uint32_t micros();
static bool acro_init(bool ignore_checks);
static void acro_run();
static void get_pilot_desired_angle_rates(int16_t roll_in, int16_t pitch_in, int16_t yaw_in, float &roll_out, float &pitch_out, float &yaw_out);
static bool althold_init(bool ignore_checks);
static void althold_run();
static bool auto_init(bool ignore_checks);
static void auto_run();
static void auto_takeoff_start(float final_alt);
static void auto_takeoff_run();
static void auto_wp_start(const Vector3f& destination);
static void auto_wp_run();
static void auto_spline_run();
static void auto_land_start();
static void auto_land_start(const Vector3f& destination);
static void auto_land_run();
static void auto_rtl_start();
void auto_rtl_run();
static void auto_circle_movetoedge_start();
static void auto_circle_start();
void auto_circle_run();
uint8_t get_default_auto_yaw_mode(bool rtl);
void set_auto_yaw_mode(uint8_t yaw_mode);
float get_auto_heading(void);
static void autotune_start();
static void autotune_stop();
static bool autotune_init(bool ignore_checks);
static void autotune_run();
static void autotune_attitude_control();
static void autotune_failed();
static void autotune_backup_gains_and_initialise();
static void autotune_load_orig_gains();
static void autotune_load_tuned_gains();
static void autotune_load_intra_test_gains();
static void autotune_load_twitch_gains();
static void autotune_save_tuning_gains();
void autotune_update_gcs(uint8_t message_id);
static bool circle_init(bool ignore_checks);
static void circle_run();
static bool drift_init(bool ignore_checks);
static void drift_run();
static bool flip_init(bool ignore_checks);
static void flip_stop();
static void flip_run();
static bool guided_init(bool ignore_checks);
static void guided_set_destination(const Vector3f& destination);
static void guided_run();
static bool hybrid_init(bool ignore_checks);
static void hybrid_run();
static void hybrid_update_pilot_lean_angle(int16_t &lean_angle_filtered, int16_t &lean_angle_raw);
static int16_t hybrid_mix_controls(float mix_ratio, int16_t first_control, int16_t second_control);
static void hybrid_update_brake_angle_from_velocity(int16_t &brake_angle, float velocity);
static void hybrid_update_wind_comp_estimate();
static void hybrid_get_wind_comp_lean_angles(int16_t &roll_angle, int16_t &pitch_angle);
static void hybrid_roll_controller_to_pilot_override();
static void hybrid_pitch_controller_to_pilot_override();
static bool land_init(bool ignore_checks);
static void land_run();
static void land_gps_run();
static void land_nogps_run();
static float get_throttle_land();
static bool update_land_detector();
static void land_do_not_use_GPS();
static bool loiter_init(bool ignore_checks);
static void loiter_run();
static void read_control_switch();
static uint8_t readSwitch(void);
static void reset_control_switch();
static uint8_t read_3pos_switch(int16_t radio_in);
static void read_aux_switches();
static void init_aux_switches();
static void do_aux_switch_function(int8_t ch_function, uint8_t ch_flag);
static void save_trim();
static void auto_trim();
static bool ofloiter_init(bool ignore_checks);
static void ofloiter_run();
static int32_t get_of_roll(int32_t input_roll);
static int32_t get_of_pitch(int32_t input_pitch);
static void reset_optflow_I(void);
static bool rtl_init(bool ignore_checks);
static void rtl_run();
static void rtl_climb_start();
static void rtl_return_start();
static void rtl_climb_return_run();
static void rtl_loiterathome_start();
static void rtl_loiterathome_run();
static void rtl_descent_start();
static void rtl_descent_run();
static void rtl_land_start();
static void rtl_land_run();
static float get_RTL_alt();
static bool sport_init(bool ignore_checks);
static void sport_run();
static bool stabilize_init(bool ignore_checks);
static void stabilize_run();
void crash_check();
void parachute_check();
static void parachute_release();
static void parachute_manual_release();
static void failsafe_radio_on_event();
static void failsafe_radio_off_event();
static void failsafe_battery_event(void);
static void failsafe_gps_check();
static void failsafe_gps_off_event(void);
static void failsafe_gcs_check();
static void failsafe_gcs_off_event(void);
static void update_events();
void failsafe_enable();
void failsafe_disable();
void failsafe_check();
void fence_check();
static void fence_send_mavlink_status(mavlink_channel_t chan);
static bool set_mode(uint8_t mode);
static void update_flight_mode();
static void exit_mode(uint8_t old_control_mode, uint8_t new_control_mode);
static bool mode_requires_GPS(uint8_t mode);
static bool manual_flight_mode(uint8_t mode);
static void get_angle_targets_for_reporting(Vector3f& targets);
static void heli_init();
static int16_t get_pilot_desired_collective(int16_t control_in);
static void check_dynamic_flight(void);
static void heli_update_landing_swash();
static void heli_update_rotor_speed_targets();
static bool heli_acro_init(bool ignore_checks);
static void heli_acro_run();
static bool heli_stabilize_init(bool ignore_checks);
static void heli_stabilize_run();
static void read_inertia();
static void read_inertial_altitude();
static void update_notify();
static void motor_test_output();
static bool mavlink_motor_test_check(mavlink_channel_t chan);
static uint8_t mavlink_motor_test_start(mavlink_channel_t chan, uint8_t motor_seq, uint8_t throttle_type, uint16_t throttle_value, float timeout_sec);
static void motor_test_stop();
static void arm_motors_check();
static void auto_disarm_check();
static void init_arm_motors();
static void pre_arm_checks(bool display_failure);
static void pre_arm_rc_checks();
static bool pre_arm_gps_checks(bool display_failure);
static bool arm_checks(bool display_failure);
static void init_disarm_motors();
static void set_servos_4();
static void run_nav_updates(void);
static void calc_position();
static void calc_distance_and_bearing();
static void calc_wp_distance();
static void calc_wp_bearing();
static void calc_home_distance_and_bearing();
static void run_autopilot();
void perf_info_reset();
void perf_info_check_loop_time(uint32_t time_in_micros);
uint16_t perf_info_get_num_loops();
uint32_t perf_info_get_max_time();
uint16_t perf_info_get_num_long_running();
Vector3f pv_latlon_to_vector(int32_t lat, int32_t lon, int32_t alt);
Vector3f pv_location_to_vector(Location loc);
int32_t pv_get_lat(const Vector3f pos_vec);
int32_t pv_get_lon(const Vector3f &pos_vec);
float pv_get_horizontal_distance_cm(const Vector3f &origin, const Vector3f &destination);
float pv_get_bearing_cd(const Vector3f &origin, const Vector3f &destination);
static void default_dead_zones();
static void init_rc_in();
static void init_rc_out();
void output_min();
static void read_radio();
static void set_throttle_and_failsafe(uint16_t throttle_pwm);
static void trim_radio();
static void init_sonar(void);
static void init_barometer(bool full_calibration);
static int32_t read_barometer(void);
static int16_t read_sonar(void);
static void init_compass();
static void init_optflow();
static void read_battery(void);
void read_receiver_rssi(void);
static void report_batt_monitor();
static void report_sonar();
static void report_frame();
static void report_radio();
static void report_ins();
static void report_flight_modes();
void report_optflow();
static void print_radio_values();
static void print_switch(uint8_t p, uint8_t m, bool b);
static void print_accel_offsets_and_scaling(void);
static void print_gyro_offsets(void);
static void report_compass();
static void print_blanks(int16_t num);
static void print_divider(void);
static void print_enabled(bool b);
static void init_esc();
static void report_version();
static void init_ardupilot();
static void startup_ground(bool force_gyro_cal);
static bool GPS_ok();
static void update_auto_armed();
static void check_usb_mux(void);
static void print_hit_enter();

#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\ArduCopter.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\APM_Config.h"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\APM_Config_mavlink_hil.h"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\AP_State.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\Attitude.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\GCS_Mavlink.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\Log.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\Parameters.h"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\Parameters.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\UserCode.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\UserVariables.h"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\commands.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\commands_logic.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\compassmot.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\compat.h"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\compat.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\config.h"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\config_channels.h"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_acro.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_althold.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_auto.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_autotune.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_circle.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_drift.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_flip.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_guided.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_hybrid.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_land.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_loiter.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_modes.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_ofloiter.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_rtl.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_sport.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\control_stabilize.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\crash_check.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\defines.h"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\events.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\failsafe.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\fence.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\flight_mode.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\heli.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\heli_control_acro.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\heli_control_stabilize.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\inertia.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\leds.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\motor_test.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\motors.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\navigation.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\perf_info.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\position_vector.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\radio.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\sensors.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\setup.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\system.pde"
#include "C:\Users\ExtraUser\Documents\GitHub\ardupilot\ArduCopter\test.pde"
