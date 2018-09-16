// test the mapping between the following units:
//  1. Alexa brightness value (6 to 254) 
//  2. floating point factor (0.00 to 1.00)
//  3. integer percentage

// compile with
//  g++ -o TestColorPluginValueMappings TestColorPluginValueMappings.cpp
#include <stdio.h>
#include <stdint.h>

uint8_t FactorToAlexa(float factor) {
  uint8_t alexaValue = (uint8_t)(253.0f * factor + 1.5f);
  if(alexaValue > 254)
    alexaValue = 254;
  else if(alexaValue < 2) // < 1% is 0%
    alexaValue = 0;
  return alexaValue;
}

float AlexaToFactor(uint8_t alexaValue) {
  float factor = (alexaValue) / 253.0f;
  if(factor > 1.0f)
    factor = 1.0f;
  return factor;
}

struct mapEntry {
	int percent;
	int alexa;
};

// the percent to Alexa values mapping table. Created by setting a percent value via
// Alexa voice command and wrote down the Alexa command value from the request
struct mapEntry testData[] = {
	{ 1, 4 },
	{ 2, 6 },
	{ 3, 9 },
	{ 4, 11 },
	{ 5, 14 },
	{ 6, 16 },
	{ 7, 19 },
	{ 8, 21 },
	{ 9, 24 },
	{ 10, 26 },
	{ 11, 29 },
	{ 12, 31 },
	{ 13, 34 },
	{ 14, 36 },
	{ 15, 39 },
	{ 16, 41 },
	{ 17, 44 },
	{ 18, 47 },
	{ 19, 49 },
	{ 20, 52 },
	{ 21, 54 },
	{ 22, 57 },
	{ 23, 59 },
	{ 24, 62 },
	{ 25, 64 },
	{ 26, 67 },
	{ 27, 69 },
	{ 28, 72 },
	{ 29, 74 },
	{ 30, 77 },
	{ 31, 79 },
	{ 32, 82 },
	{ 33, 84 },
	{ 34, 87 },
	{ 35, 90 },
	{ 36, 92 },
	{ 37, 95 },
	{ 38, 97 },
	{ 39, 100 },
	{ 40, 102 },
	{ 41, 105 },
	{ 42, 107 },
	{ 43, 110 },
	{ 44, 112 },
	{ 45, 115 },
	{ 46, 117 },
	{ 47, 120 },
	{ 48, 122 },
	{ 49, 125 },
	{ 50, 128 },
	{ 51, 130 },
	{ 52, 133 },
	{ 53, 135 },
	{ 54, 138 },
	{ 55, 140 },
	{ 56, 143 },
	{ 57, 145 },
	{ 58, 148 },
	{ 59, 150 },
	{ 60, 153 },
	{ 61, 155 },
	{ 62, 158 },
	{ 63, 160 },
	{ 64, 163 },
	{ 65, 165 },
	{ 66, 168 },
	{ 67, 171 },
	{ 68, 173 },
	{ 69, 176 },
	{ 70, 178 },
	{ 71, 181 },
	{ 72, 183 },
	{ 73, 186 },
	{ 74, 188 },
	{ 75, 191 },
	{ 76, 193 },
	{ 77, 196 },
	{ 78, 198 },
	{ 79, 201 },
	{ 80, 203 },
	{ 81, 206 },
	{ 82, 208 },
	{ 83, 211 },
	{ 84, 214 },
	{ 85, 216 },
	{ 86, 219 },
	{ 87, 221 },
	{ 88, 224 },
	{ 89, 226 },
	{ 90, 229 },
	{ 91, 231 },
	{ 92, 234 },
	{ 93, 236 },
	{ 94, 239 },
	{ 95, 241 },
	{ 96, 244 },
	{ 97, 246 },
	{ 98, 249 },
	{ 99, 251 },
	{ 100, 254 }
};

//******************************

#define vsnprintf snprintf
#define snprintf_P snprintf
#define MqttPublishPrefixTopic_P(x, y)
typedef uint8_t byte;
enum SupportedModules {
  SONOFF_BASIC,
  SONOFF_RF,
  SONOFF_SV,
  SONOFF_TH,
  SONOFF_DUAL,
  SONOFF_POW,
  SONOFF_4CH,
  SONOFF_S2X,
  SLAMPHER,
  SONOFF_TOUCH,
  SONOFF_LED,
  CH1,
  CH4,
  MOTOR,
  ELECTRODRAGON,
  EXS_RELAY,
  WION,
  WEMOS,
  SONOFF_DEV,
  H801,
  SONOFF_SC,
  SONOFF_BN,
  SONOFF_4CHPRO,
  HUAFAN_SS,
  SONOFF_BRIDGE,
  SONOFF_B1,
  AILIGHT,
  SONOFF_T11,
  SONOFF_T12,
  SONOFF_T13,
  SUPLA1,
  WITTY,
  YUNSHAN,
  MAGICHOME,
  LUANIHVIO,
  KMC_70011,
  ARILUX_LC01,
  ARILUX_LC11,
  SONOFF_DUAL_R2,
  ARILUX_LC06,
  SONOFF_S31,
  ZENGGE_ZF_WF017,
  SONOFF_POW_R2,
  SONOFF_IFAN02,
  BLITZWOLF_BWSHP2,
  SHELLY1,
  SHELLY2,
  PHILIPS,
  MAXMODULE };
enum ExecuteCommandPowerOptions { POWER_OFF, POWER_ON, POWER_TOGGLE, POWER_BLINK, POWER_BLINK_STOP, power_nu1, POWER_OFF_NO_STATE, POWER_ON_NO_STATE, power_nu2, POWER_SHOW_STATE };
enum CommandSource { SRC_IGNORE, SRC_MQTT, SRC_RESTART, SRC_BUTTON, SRC_SWITCH, SRC_BACKLOG, SRC_SERIAL, SRC_WEBGUI, SRC_WEBCOMMAND, SRC_WEBCONSOLE, SRC_PULSETIMER,
                     SRC_TIMER, SRC_RULE, SRC_MAXPOWER, SRC_MAXENERGY, SRC_LIGHT, SRC_KNX, SRC_DISPLAY, SRC_WEMO, SRC_HUE, SRC_RETRY, SRC_MAX };
enum LightTypes {LT_BASIC, LT_PWM1, LT_PWM2, LT_PWM3, LT_PWM4, LT_PWM5, LT_PWM6, LT_PWM7, LT_NU8, LT_NU9, LT_NU10, LT_WS2812, LT_RGBW, LT_RGBWC};
enum LichtSubtypes {LST_NONE, LST_SINGLE, LST_COLDWARM, LST_RGB, LST_RGBW, LST_RGBWC};
typedef union {                            // Restricted by MISRA-C Rule 18.4 but so useful...
  uint32_t data;                           // Allow bit manipulation using SetOption
  struct {                                 // SetOption0 .. SetOption31
    uint32_t save_state : 1;               // bit 0
    uint32_t button_restrict : 1;          // bit 1
    uint32_t value_units : 1;              // bit 2
    uint32_t mqtt_enabled : 1;             // bit 3
    uint32_t mqtt_response : 1;            // bit 4
    uint32_t mqtt_power_retain : 1;        // CMND_POWERRETAIN
    uint32_t mqtt_button_retain : 1;       // CMND_BUTTONRETAIN
    uint32_t mqtt_switch_retain : 1;       // CMND_SWITCHRETAIN
    uint32_t temperature_conversion : 1;   // bit 8
    uint32_t mqtt_sensor_retain : 1;       // CMND_SENSORRETAIN
    uint32_t mqtt_offline : 1;             // bit 10
    uint32_t button_swap : 1;              // bit 11 (v5.1.6)
    uint32_t stop_flash_rotate : 1;        // bit 12 (v5.2.0)
    uint32_t button_single : 1;            // bit 13 (v5.4.0)
    uint32_t interlock : 1;                // bit 14 (v5.6.0)
    uint32_t pwm_control : 1;              // bit 15 (v5.8.1)
    uint32_t ws_clock_reverse : 1;         // bit 16 (v5.8.1)
    uint32_t decimal_text : 1;             // bit 17 (v5.8.1)
    uint32_t light_signal : 1;             // bit 18 (v5.10.0c)
    uint32_t hass_discovery : 1;           // bit 19 (v5.11.1a)
    uint32_t not_power_linked : 1;         // bit 20 (v5.11.1f)
    uint32_t no_power_on_check : 1;        // bit 21 (v5.11.1i)
    uint32_t mqtt_serial : 1;              // bit 22 (v5.12.0f)
    uint32_t mqtt_serial_raw : 1;          // bit 23 (v6.1.1c)
    uint32_t rules_once : 1;               // bit 24 (v5.12.0k) - free since v5.14.0b
    uint32_t knx_enabled : 1;              // bit 25 (v5.12.0l) KNX
    uint32_t device_index_enable : 1;      // bit 26 (v5.13.1a)
    uint32_t knx_enable_enhancement : 1;   // bit 27 (v5.14.0a) KNX
    uint32_t rf_receive_decimal : 1;       // bit 28 (v6.0.0a)
    uint32_t ir_receive_decimal : 1;       // bit 29 (v6.0.0a)
    uint32_t hass_light : 1;               // bit 30 (v6.0.0b)
    uint32_t global_state : 1;             // bit 31 (v6.1.0)
  };
} SysBitfield;

struct SYSCFG {
  uint8_t       light_dimmer;              // 49E
  uint8_t       module;                    // 474
  uint8_t       light_color[5];            // 498
  SysBitfield   flag;                      // 010
} Settings;

#define LOGSZ                  512          // Max number of characters in log
#define D_LOG_HTTP " HTTP"
#define D_HUE_API " HUE API"
#define PSTR(x) x
#define LOG_LEVEL_DEBUG_MORE 0

float light_hue = 0.0;
float light_saturation = 0.0;
float light_brightness = 0.0;
uint8_t light_current_color[5];
uint8_t light_signal_color[5];
uint8_t light_type = 0;                     // Light types
uint8_t light_subtype = 0;
uint8_t light_power = 0;
uint8_t light_device = 0;
char log_data[LOGSZ];                       // Logging

void AddLog(int) {
  printf("%s\n", log_data);
}

void ExecuteCommandPower(byte device, byte state, int source)
{
}

void LightState(uint8_t append)
{
}

void LightPreparePower()
{
  if (Settings.light_dimmer && !(light_power)) {
    if (!Settings.flag.not_power_linked) {
      ExecuteCommandPower(light_device, POWER_ON_NO_STATE, SRC_LIGHT);
    }
  }
  else if (!Settings.light_dimmer && light_power) {
    ExecuteCommandPower(light_device, POWER_OFF_NO_STATE, SRC_LIGHT);
  }
#ifdef USE_DOMOTICZ
  DomoticzUpdatePowerState(light_device);
#endif  // USE_DOMOTICZ

  LightState(0);
}

void LightSetColor()
{
  uint8_t highest = 0;

  for (byte i = 0; i < light_subtype; i++) {
    if (highest < light_current_color[i]) {
      highest = light_current_color[i];
    }
  }
  float mDim = (float)highest / 2.55f;
  //Settings.light_dimmer = (uint8_t)(mDim + 0.5f); // TODO: do we need to round up here?
  Settings.light_dimmer = (uint8_t)mDim;
  float dimmer = 100.0f / mDim;
  for (byte i = 0; i < light_subtype; i++) {
    float temp = (float)light_current_color[i] * dimmer;
    Settings.light_color[i] = (uint8_t)temp;
  }
}

void LightSetColorTemp(uint16_t ct)
{
/* Color Temperature (https://developers.meethue.com/documentation/core-concepts)
 *
 * ct = 153 = 2000K = Warm = CCWW = 00FF
 * ct = 500 = 6500K = Cold = CCWW = FF00
 */
  uint16_t my_ct = ct - 153;
  if (my_ct > 347) {
    my_ct = 347;
  }
  uint16_t icold = (100 * (347 - my_ct)) / 136;
  uint16_t iwarm = (100 * my_ct) / 136;
  if (PHILIPS == Settings.module) {
    // Xiaomi Philips bulbs follow a different scheme:
    // channel 0=intensity, channel2=temperature
    Settings.light_color[1] = (uint8_t)icold;
  } else
  if (LST_RGBWC == light_subtype) {
    Settings.light_color[0] = 0;
    Settings.light_color[1] = 0;
    Settings.light_color[2] = 0;
    Settings.light_color[3] = (uint8_t)icold;
    Settings.light_color[4] = (uint8_t)iwarm;
  } else {
    Settings.light_color[0] = (uint8_t)icold;
    Settings.light_color[1] = (uint8_t)iwarm;
  }
}

void LightSetDimmer(uint8_t myDimmer)
{
  float temp;
  if(myDimmer == 0) // avoid division by zero
    myDimmer = 1;
  float dimmer = 100.0f / (float)myDimmer;

  if (PHILIPS == Settings.module) {
    // Xiaomi Philips bulbs use two PWM channels with a different scheme:
    temp = (float)Settings.light_color[0] / dimmer; // channel 1 is intensity
    light_current_color[0] = (uint8_t)temp;
    temp = (float)Settings.light_color[1];          // channel 2 is temperature
    light_current_color[1] = (uint8_t)temp;
    return;
  }
  if (LT_PWM1 == light_type) {
    Settings.light_color[0] = 255;    // One PWM channel only supports Dimmer but needs max color
  }
  for (byte i = 0; i < light_subtype; i++) {
    if (Settings.flag.light_signal) {
      temp = (float)light_signal_color[i] / dimmer;
    } else {
      temp = (float)Settings.light_color[i] / dimmer;
    }
    light_current_color[i] = (uint8_t)temp;
  }
}

float LightUint8ToFactor(uint8_t v) {
  float fact = ((float)v + 0.5f) / 255.0f;
  if(fact > 1.0f)
    fact = 1.0f;
  return fact;
}

void LightRgbToHsb()
{
  LightSetDimmer(Settings.light_dimmer);

  // convert colors to float between (0.0 - 1.0)
  float r = LightUint8ToFactor(light_current_color[0]);
  float g = LightUint8ToFactor(light_current_color[1]);
  float b = LightUint8ToFactor(light_current_color[2]);

  float max = (r > g && r > b) ? r : (g > b) ? g : b;
  float min = (r < g && r < b) ? r : (g < b) ? g : b;

  float d = max - min;

  light_hue = 0.0;
  light_brightness = max;
  light_saturation = (0.0f == light_brightness) ? 0 : (d / light_brightness);

  if (d != 0.0f)
  {
    if (r == max) {
      light_hue = (g - b) / d + (g < b ? 6.0f : 0.0f);
    } else if (g == max) {
      light_hue = (b - r) / d + 2.0f;
    } else {
      light_hue = (r - g) / d + 4.0f;
    }
    light_hue /= 6.0f;
  }
}

void LightHsbToRgb()
{
  float r;
  float g;
  float b;

  float h = light_hue;
  float s = light_saturation;
  float v = light_brightness;

  if (0.0f == light_saturation) {
    r = g = b = v;                      // Achromatic or black
  } else {
    if (h < 0.0f) {
      h += 1.0f;
    }
    else if (h >= 1.0f) {
      h -= 1.0f;
    }
    h *= 6.0f;
    int i = (int)h;
    float f = h - i;
    float q = v * (1.0f - s * f);
    float p = v * (1.0f - s);
    float t = v * (1.0f - s * (1.0f - f));
    switch (i) {
      case 0:
        r = v;
        g = t;
        b = p;
        break;
      case 1:
        r = q;
        g = v;
        b = p;
        break;
      case 2:
        r = p;
        g = v;
        b = t;
        break;
      case 3:
        r = p;
        g = q;
        b = v;
        break;
      case 4:
        r = t;
        g = p;
        b = v;
        break;
      default:
        r = v;
        g = p;
        b = q;
        break;
      }
  }

  light_current_color[0] = (uint8_t)(r * 255.0f);
  light_current_color[1] = (uint8_t)(g * 255.0f);
  light_current_color[2] = (uint8_t)(b * 255.0f);
  light_current_color[3] = 0;
  light_current_color[4] = 0;
}

void LightGetHsb(float *hue, float *sat, float *bri, bool gotct)
{
  if (light_subtype > LST_COLDWARM && !gotct) {
    LightRgbToHsb();
    *hue = light_hue;
    *sat = light_saturation;
    *bri = light_brightness;
    // TODO: remove log
    snprintf_P(log_data, sizeof(log_data), PSTR(D_LOG_HTTP D_HUE_API " ALightGetHsb(bri=%d)"), (int16_t)(*bri*10000.0f));
    AddLog(LOG_LEVEL_DEBUG_MORE);
  } else {
    *hue = 0;
    *sat = 0;
    *bri = ((float)(Settings.light_dimmer) + 0.397f) / 100.0f;
    // TODO: remove log
    snprintf_P(log_data, sizeof(log_data), PSTR(D_LOG_HTTP D_HUE_API " BLightGetHsb(bri=%d)"), (int16_t)(*bri*10000.0f));
    AddLog(LOG_LEVEL_DEBUG_MORE);
  }
}

uint8_t LightFactorToPercent(float factor) {
  uint8_t tmp = (uint8_t)(factor * 100.0f + 0.2f);
  if(tmp > 100)
    tmp = 100;
  return tmp;
}

void LightSetHsb(float hue, float sat, float bri, uint16_t ct, bool gotct)
{
  if (light_subtype > LST_COLDWARM) {
    if ((LST_RGBWC == light_subtype) && (gotct)) {
      Settings.light_dimmer = LightFactorToPercent(bri);
      if (ct > 0) {
        LightSetColorTemp(ct);
      }
    } else {
      light_hue = hue;
      light_saturation = sat;
      light_brightness = bri;
      LightHsbToRgb();
      LightSetColor();
    }
    LightPreparePower();
    MqttPublishPrefixTopic_P(RESULT_OR_STAT, PSTR(D_CMND_COLOR));
  } else {
    Settings.light_dimmer = LightFactorToPercent(bri);
    if (LST_COLDWARM == light_subtype) {
      if (ct > 0) {
        LightSetColorTemp(ct);
      }
      LightPreparePower();
      MqttPublishPrefixTopic_P(RESULT_OR_STAT, PSTR(D_CMND_COLOR));
    } else {
      LightPreparePower();
      MqttPublishPrefixTopic_P(RESULT_OR_STAT, PSTR(D_CMND_DIMMER));
    }
  }
}


//******************************

bool testHsb(uint8_t percent, float hue, float sat, float bri, uint16_t ct, bool gotct) {
  LightSetHsb(hue, sat, bri, ct, gotct);

  float hue2, sat2, bri2;
  LightGetHsb(&hue2, &sat2, &bri2, gotct);

    uint8_t bri1int = FactorToAlexa(bri);
    uint8_t bri2int = FactorToAlexa(bri2);

    if(bri1int != bri2int) {
          printf("Value mismatch: percent=%d, in=%d, out=%d\n", percent, bri1int, bri2int);
      return false;
    }
    return true;
}

int main() {
    int errorCount = 0;

    // only one PWM channel, no color, no ct
    light_type = LT_PWM1;
    Settings.module = SONOFF_BN;
    bool gotct = false;
    float hue = 0.5, sat = 0.5, bri = 0.5;
    uint16_t ct = 500;
	errorCount = 0;
	printf("Test4 START\n");
	for(int i = 0; i < (sizeof(testData) / sizeof(testData[0])); i++) {
		int v1 = testData[i].percent;
		bri = AlexaToFactor(testData[i].alexa);
        if(!testHsb(v1, hue, sat, bri, ct, gotct))
            errorCount++;
	}

	printf("Test4 %s, errorcount=%d\n", errorCount > 0 ? "FAILED" : "SUCCEEDED", errorCount);

}
