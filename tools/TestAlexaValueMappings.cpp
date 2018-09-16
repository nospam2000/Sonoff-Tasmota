// test the mapping between the following units:
//  1. Alexa brightness value (6 to 254) 
//  2. floating point factor (0.00 to 1.00)
//  3. integer percentage

// compile with
//  g++ -o TestAlexaValueMappings TestAlexaValueMappings.c

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

int main() {
	// test roundtrip AlexaToFactor(FactorToAlexa())
	int errorCount = 0;
	for(int v1 = 0; v1 <= 100; v1++) {
		int v2 = AlexaToFactor(FactorToAlexa(v1 / 100.0f)) * 100.0f;
		if(v1 != v2)
		{
			printf("Test1: Value mismatch: v1=%d, v=%d, delta=%d\n", v1, v2, v1-v2);
			errorCount++;
		}
	}
	printf("Test1 %s\n", errorCount > 0 ? "FAILED" : "SUCCEEDED");

	// test rounding problems when converting factor to integer percent
	errorCount = 0;
	for(int v1 = 0; v1 <= 100; v1++) {
		// like in LightSetHsb():
		//   uint8_t tmp = (uint8_t)(bri * 100.0f + 0.5f);
		int v2 = (int)((v1 / 100.0f) * 100.0f + 0.5f); // the +0.5 is essential
		if(v1 != v2)
		{
			printf("Test2: Value mismatch: v1=%d, v2=%d, delta=%d\n", v1, v2, v1-v2);
			errorCount++;
		}
	}
	printf("Test2 %s\n", errorCount > 0 ? "FAILED" : "SUCCEEDED");

	// test FactorToAlexa()
	errorCount = 0;
	for(int i = 0; i < (sizeof(testData) / sizeof(testData[0])); i++) {
		int v1 = testData[i].alexa;
		int v2 = FactorToAlexa(testData[i].percent / 100.0f);
		if(v1 != v2)
		{
			printf("Test3: Value mismatch: percent=%d, v1=%d, v2=%d, delta=%d\n", testData[i].percent, v1, v2, v1-v2);
			errorCount++;
		}
	}
	printf("Test3 %s\n", errorCount > 0 ? "FAILED" : "SUCCEEDED");

	// test AlexaToFactor()
	errorCount = 0;
	for(int i = 0; i < (sizeof(testData) / sizeof(testData[0])); i++) {
		int v1 = testData[i].percent;
		int v2 = AlexaToFactor(testData[i].alexa) * 100.0f;
		if(v1 != v2)
		{
			printf("Test4: Value mismatch: percent=%d, v1=%d, v2=%d, delta=%d\n", testData[i].percent, v1, v2, v1-v2);
			errorCount++;
		}
	}
	printf("Test4 %s\n", errorCount > 0 ? "FAILED" : "SUCCEEDED");
}
