#include "config.hpp"

DCMotor motor1;
DCMotor motor2;

void init(){
    // motor pin initialization
    gpio_init(MOTOR_DIR_PIN1);
    gpio_set_dir(MOTOR_DIR_PIN1, GPIO_OUT); 
    gpio_put(MOTOR_DIR_PIN1, 0); // Initial direction
    gpio_init(MOTOR_DIR_PIN2);
    gpio_set_dir(MOTOR_DIR_PIN2, GPIO_OUT);
    gpio_put(MOTOR_DIR_PIN2, 0); // Initial direction
    gpio_init(MOTOR_PWM_PIN1);
    gpio_set_dir(MOTOR_PWM_PIN1, GPIO_OUT);
    gpio_put(MOTOR_PWM_PIN1, 0); // Initial PWM low
    gpio_init(MOTOR_PWM_PIN2);
    gpio_set_dir(MOTOR_PWM_PIN2, GPIO_OUT);
    gpio_put(MOTOR_PWM_PIN2, 0); // Initial PWM low
    sleep_ms(1000);

    motor1.attach(MOTOR_PWM_PIN1, MOTOR_DIR_PIN1);
    motor2.attach(MOTOR_PWM_PIN2, MOTOR_DIR_PIN2);
    sleep_ms(1000);

    motor1.begin(true, 20000);
    motor2.begin(true, 20000);
    sleep_ms(1000);

    // motor1.stop();
    // motor2.stop();
}

void core1_entry(){
    while(true){
        absolute_time_t next_time = make_timeout_time_ms(100);  // 今から100ms後
        motor1.setSpeed(-0.8f); // Forward at 50% speed
        motor2.setSpeed(0.8f);
        busy_wait_until(next_time);  // 100ms待機
    }
}

int main(){
    init();
    stdio_init_all();
    cyw43_arch_init();
    sleep_ms(1000); // Wait for serial to initialize

    multicore_launch_core1(core1_entry);

    while(true){
        absolute_time_t next_time = make_timeout_time_ms(100);  // 今から100ms後
        static bool led_on = false;
        led_on = !led_on;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);
        busy_wait_until(next_time);  // 500ms待機
    }
}