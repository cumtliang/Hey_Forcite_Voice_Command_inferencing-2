/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// Generated on: 16.10.2023 23:53:51

#include <stdio.h>
#include <stdlib.h>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#elif defined __ICCARM__
#define ALIGN(x) __attribute__((aligned(x)))
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#ifndef CONFIG_IDF_TARGET_ESP32S3
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#else
#define EI_MAX_SCRATCH_BUFFER_COUNT 8
#endif // CONFIG_IDF_TARGET_ESP32S3
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX) || defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
constexpr int kTensorArenaSize = 3296;
#else
constexpr int kTensorArenaSize = 2272;
#endif

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

typedef struct {
  TfLiteTensor tensor;
  int16_t index;
} TfLiteTensorWithIndex;

typedef struct {
  TfLiteEvalTensor tensor;
  int16_t index;
} TfLiteEvalTensorWithIndex;

TfLiteContext ctx{};
static const int MAX_TFL_TENSOR_COUNT = 4;
static TfLiteTensorWithIndex tflTensors[MAX_TFL_TENSOR_COUNT];
static const int MAX_TFL_EVAL_COUNT = 4;
static TfLiteEvalTensorWithIndex tflEvalTensors[MAX_TFL_EVAL_COUNT];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[11];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,715 } };
const TfArray<1, float> quant0_scale = { 1, { 0.031775142997503281, } };
const TfArray<1, int> quant0_zero = { 1, { -3 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int32_t tensor_data1[4] = { 1, 1, 55, 13, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data2[4] = { 1, 55, 1, 8, };
const TfArray<1, int> tensor_dimension2 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data3[4] = { 1, 1, 28, 8, };
const TfArray<1, int> tensor_dimension3 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data4[4] = { 1, 28, 1, 16, };
const TfArray<1, int> tensor_dimension4 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data5[2] = { -1, 224, };
const TfArray<1, int> tensor_dimension5 = { 1, { 2 } };
const ALIGN(16) int32_t tensor_data6[4] = { 1436, -1380, -1503, -1475, };
const TfArray<1, int> tensor_dimension6 = { 1, { 4 } };
const TfArray<1, float> quant6_scale = { 1, { 2.6546184017206542e-05, } };
const TfArray<1, int> quant6_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(16) int8_t tensor_data7[4*224] = { 
  80, 81, 120, -11, 29, -58, -77, 4, 121, 71, 65, 15, -20, 111, 32, -62, -3, 71, -58, 18, 51, -55, -50, 33, 30, 64, 99, 73, -73, 87, -36, -11, 18, 98, -47, -13, 40, 34, 21, 23, 31, -47, 32, 7, 89, 25, 99, -56, 57, 81, 43, -44, 30, -12, -60, 70, -62, -40, 71, -55, 8, 38, 121, 111, 70, -51, -52, 21, -69, 47, 113, -6, 10, 3, 16, -31, -44, 40, 65, -30, -64, 33, -1, 71, 51, -4, 117, 57, 53, 117, 98, 73, 38, -42, 33, -56, 92, 82, 37, 118, 11, 94, 108, -46, -67, 12, -61, 12, 3, 58, 102, 112, 47, 116, 3, 34, 83, 125, 13, -16, 114, 86, 53, 10, -9, 33, 37, 65, 9, 84, -53, -74, -45, -30, 83, 109, 110, 80, 30, 58, 10, -56, 49, 82, 94, -24, 64, 71, -43, 109, -5, -45, 25, 112, 18, -23, -3, -57, 118, 119, -38, 69, 118, 111, -24, 22, 60, 25, -77, 83, 82, 64, 4, -28, 103, 40, 122, 8, -46, -29, 13, 64, -72, 111, -7, 46, 0, -66, 76, 122, 20, -10, 25, -32, 49, -47, -73, -50, -71, 43, -57, 91, -57, -2, -46, 120, 46, -1, -49, -5, -45, 110, 65, 62, 39, -15, -76, -14, -46, -67, -10, -12, 40, -57, 
  34, -41, -98, -115, -95, -100, -11, 3, -58, -12, 56, 2, 37, -41, 4, 25, 37, -4, 4, 74, -91, -40, -2, -120, 56, -26, -60, 63, 24, 54, 1, -112, 7, -92, 9, -82, -4, -118, -105, -10, -84, 1, -40, 69, -120, 22, -119, -89, 38, 51, 70, 53, -89, -94, -35, -84, 44, 5, 57, 58, -79, -28, -27, 32, -118, -26, 66, 73, -34, -57, 2, -87, -92, -49, 28, -93, 73, 33, -48, -59, -17, -63, -71, 7, -96, -111, -107, 30, 69, 11, -52, -96, -91, 3, -59, -88, -95, -12, 63, -87, -49, -43, -93, -20, -9, 59, -40, -90, -91, -102, 11, -87, -28, -75, -50, 75, -35, -120, -21, -62, -14, 6, 81, 31, 17, -36, -107, -118, 5, 27, -85, -15, 41, -102, 35, -69, -72, -25, -10, -73, -22, -85, 2, -74, -40, -55, 35, 78, 46, 61, -56, 29, -42, -55, 3, 50, 61, -43, 76, -38, 75, -13, -51, -61, -25, -46, 32, 8, -82, -25, 41, -13, -24, -52, 73, -112, -19, 72, -28, -15, -29, 67, -32, -28, 8, 50, -83, 78, 61, 51, -110, -1, 48, 20, 77, -116, 58, -19, 11, 64, 25, -102, -119, 39, -28, -19, -26, 36, 27, -97, 32, -44, -96, -25, -106, 27, 23, 48, -84, -86, -120, 37, -14, -101, 
  -103, 60, -85, -108, 49, -102, 68, 28, 30, -84, 19, 29, -12, -9, 13, 49, 71, -65, -121, 35, 67, 24, 20, -79, -90, -118, -107, -14, -116, -8, -21, 22, -74, 29, 51, 33, -19, -105, -30, 18, -14, -50, 10, 56, -57, -18, -44, -5, 40, -56, -6, -24, -9, 6, -95, -107, 66, 47, 40, -108, -85, 47, -53, -100, 34, 37, -23, -43, 27, -17, 48, -20, -83, 22, 77, -34, -52, -77, 70, -24, -12, -65, -52, 57, -100, -35, 50, -81, -96, 13, 45, 21, -116, -114, 58, -118, 11, -97, -27, 37, -40, -118, -87, 47, -9, 60, -12, -8, -52, -89, 8, -12, 65, -75, -74, -18, -13, -111, 45, 67, 26, -110, 4, -70, -11, -89, 34, -55, 36, -67, 64, -41, 28, 52, 38, -84, -72, -55, -79, -23, -123, 43, 35, 73, 61, -65, -56, 75, 1, 59, 28, 33, 28, -38, 42, -61, -85, -82, -32, -66, -122, -55, 14, -14, -2, 66, 14, 73, -47, -17, 61, -123, 5, -88, 55, -59, 32, -87, -111, -91, -29, -125, 75, -3, -81, 48, 81, -71, 72, -41, -50, -123, -88, 40, -59, 52, -6, 32, -45, 36, 50, -60, -8, 13, -34, 2, -36, -72, 44, -121, -91, -93, -15, -70, -104, -111, -59, 30, -83, -75, -12, -44, -49, -69, 
  -11, -41, -22, 21, 6, -67, 49, -52, -104, -120, -33, 13, -121, -84, 52, 73, -8, -102, -106, 71, 44, -85, 42, -1, -20, -81, 56, -116, -88, 33, -96, -110, 53, -66, -68, -87, -2, -57, -26, -99, -63, 11, -111, -95, 30, 7, -65, -14, 11, -5, -20, 43, 67, 10, 1, -13, -18, 1, -91, -110, -118, -43, -104, -55, -38, -29, 62, -69, -34, 44, -82, 16, -53, 35, 31, 70, -101, -8, -96, -120, -53, 61, -68, 54, 79, 44, -119, -9, 33, -9, -80, -97, -91, -23, -77, -102, -67, -73, -63, -115, -50, -54, -107, -96, 2, 20, 33, -61, 49, 67, 53, -48, -22, -116, -109, -75, -40, -119, -53, -71, -84, -47, 1, 12, 57, -27, -20, -127, -12, -20, 25, 24, -42, -19, -21, -98, 50, 57, 39, 9, 34, -18, -62, 10, 73, -61, -40, -8, -50, 55, 58, -4, -25, -94, 4, -63, -121, -109, -82, -101, -113, -95, -12, -51, -8, -53, -58, -78, -7, -25, -87, -25, 53, -81, 45, -1, 75, 46, 44, 4, 53, 44, -57, -91, 39, -111, -48, 56, 29, 62, -88, 16, -43, -119, -1, -101, -29, 30, 18, -89, 4, -23, 12, -109, -87, -51, -88, -122, -77, -101, -112, -14, -39, 39, -60, 40, -13, 34, -63, -104, -85, 54, -91, 25, 
};
const TfArray<2, int> tensor_dimension7 = { 2, { 4,224 } };
const TfArray<1, float> quant7_scale = { 1, { 0.0016247385647147894, } };
const TfArray<1, int> quant7_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(16) int32_t tensor_data8[16] = { -625, 1106, -799, -903, -882, 1173, -538, 654, -731, 1247, -528, -511, -532, 1366, 1064, 1635, };
const TfArray<1, int> tensor_dimension8 = { 1, { 16 } };
const TfArray<16, float> quant8_scale = { 16, { 3.4225067793158814e-05, 3.8658276025671512e-05, 3.098724118899554e-05, 3.2001538784243166e-05, 3.3708587579894811e-05, 4.0198592614615336e-05, 3.6878373066429049e-05, 3.8633861549897119e-05, 3.6359342630021274e-05, 3.5047611163463444e-05, 3.3399250241927803e-05, 3.7208454159554094e-05, 3.469027069513686e-05, 3.6453006032388657e-05, 3.8680609577568248e-05, 2.8527343602036126e-05, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(16) int8_t tensor_data9[16*1*3*8] = { 
  /* [0][0][][] */ 32,39,107,84,-49,-16,3,48, -17,16,-11,-28,-96,16,108,-127, 27,68,36,38,-111,-57,75,17, 
  /* [1][0][][] */ -38,106,22,95,11,-75,-13,66, -55,-6,-33,24,97,127,79,127, 114,39,52,-93,-42,-57,13,19, 
  /* [2][0][][] */ -44,34,-67,5,-3,-65,4,57, 123,10,90,74,54,-127,-13,125, -123,64,66,-95,-58,29,98,-12, 
  /* [3][0][][] */ 54,-78,47,-61,89,-49,-127,64, 11,-99,-38,97,-11,-87,-89,28, -107,-4,-64,-64,47,-36,79,48, 
  /* [4][0][][] */ -65,-86,-103,-81,-127,-110,12,31, -105,-47,-69,-93,-47,65,23,-41, 54,75,73,-73,-101,107,-48,13, 
  /* [5][0][][] */ -63,83,76,89,-4,-91,-32,127, -60,71,-18,-30,94,101,-75,-15, -55,114,68,64,21,31,-57,85, 
  /* [6][0][][] */ 112,8,29,65,-101,-35,30,32, 41,-93,49,-109,-19,-17,25,78, -53,-127,-84,68,-8,10,-85,-92, 
  /* [7][0][][] */ 4,91,12,-117,-80,127,97,38, 80,81,97,112,90,91,42,68, 34,-3,-55,-4,117,30,94,46, 
  /* [8][0][][] */ 53,-112,91,70,10,-32,111,53, -56,-86,-105,80,82,-40,-127,100, -39,-74,71,63,10,48,-37,-28, 
  /* [9][0][][] */ 42,-56,77,110,-52,102,101,87, -28,-31,-4,-56,-6,78,-18,64, -5,-57,-34,127,-44,74,-30,127, 
  /* [10][0][][] */ -78,-57,-65,33,27,-67,61,-33, -127,-109,-34,-21,-68,-120,-101,27, -78,-13,-64,63,-92,58,-51,112, 
  /* [11][0][][] */ -125,38,-76,97,71,10,-59,-80, -69,-78,23,5,104,-127,-8,32, -46,-25,-96,69,-108,-115,-94,-40, 
  /* [12][0][][] */ -95,55,-102,127,-18,-3,95,-33, 72,-29,-119,-60,-95,64,-111,-54, 62,53,68,19,72,-126,-69,55, 
  /* [13][0][][] */ 29,2,-12,-35,-118,98,-48,-33, 94,72,-37,23,-100,-82,-47,-74, -36,36,127,13,83,-66,-58,89, 
  /* [14][0][][] */ 75,29,95,-19,-11,76,35,-53, 3,112,114,40,3,10,77,-60, 107,-95,30,127,34,-81,20,-77, 
  /* [15][0][][] */ 107,88,-18,-47,36,-35,-46,114, 19,-37,106,-9,36,-62,36,77, -92,-101,121,-74,-127,4,53,87, 
};
const TfArray<4, int> tensor_dimension9 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant9_scale = { 16, { 0.0022235370706766844, 0.0025115541648119688, 0.0020131818018853664, 0.0020790786948055029, 0.0021899824496358633, 0.0026116254739463329, 0.0023959171958267689, 0.002509967889636755, 0.0023621967993676662, 0.0022769761271774769, 0.0021698852069675922, 0.0024173620622605085, 0.0022537603508681059, 0.0023682820610702038, 0.0025130051653832197, 0.0018533668480813503, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(16) int32_t tensor_data10[8] = { 578, 506, 700, 331, -259, 506, 227, 271, };
const TfArray<1, int> tensor_dimension10 = { 1, { 8 } };
const TfArray<8, float> quant10_scale = { 8, { 8.3051658293697983e-05, 8.587211777921766e-05, 8.5527717601507902e-05, 8.3642582467291504e-05, 7.4881281761918217e-05, 8.3651575550902635e-05, 7.6533360697794706e-05, 8.3535320300143212e-05, } };
const TfArray<8, int> quant10_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const ALIGN(16) int8_t tensor_data11[8*1*3*13] = { 
  /* [0][0][][] */ 10,70,17,24,-127,-39,69,-54,-64,-44,32,-92,110, -79,-100,49,-16,-54,-38,-117,25,-1,42,64,58,10, 15,-113,37,-107,-115,58,34,-65,77,-37,25,-31,76, 
  /* [1][0][][] */ -108,-86,-24,82,-127,101,-102,111,1,-5,-33,-53,76, -83,124,45,-117,-55,127,105,63,-59,56,33,38,-85, -90,-26,-32,15,6,-107,-51,66,37,87,-67,-93,2, 
  /* [2][0][][] */ 86,125,-105,-44,-110,-108,41,75,-57,18,39,-79,47, -101,-55,73,54,-86,74,27,127,7,5,0,43,-99, -76,-92,5,-127,-89,23,-112,80,121,-55,41,-94,-29, 
  /* [3][0][][] */ -85,-13,9,-127,113,-53,91,11,114,-102,-18,-80,-26, 46,21,1,106,50,59,7,64,98,91,112,55,85, 113,-108,118,42,71,78,71,56,45,42,-58,12,-122, 
  /* [4][0][][] */ 93,-68,-21,127,-70,24,-10,116,-19,1,-108,77,65, 69,-38,103,-63,-70,-70,-87,-53,-112,-107,-31,-113,-42, -37,38,69,-31,-68,40,-80,-45,55,-80,-36,114,-70, 
  /* [5][0][][] */ -28,35,2,47,47,34,-71,6,-24,90,-50,108,18, 79,-33,20,-106,22,13,105,-55,-10,119,-125,-31,-110, 30,51,-68,116,-127,117,34,-37,89,32,-13,-65,101, 
  /* [6][0][][] */ 80,127,-13,17,-47,-40,-87,-105,-114,-123,-76,9,-64, -52,12,-27,-54,92,18,-6,-57,70,-12,48,-48,3, 112,19,53,-36,-13,-121,75,-114,-75,52,-127,77,-62, 
  /* [7][0][][] */ 100,-5,47,26,102,32,-101,85,-49,-51,91,-97,55, -90,-51,18,-27,127,-50,-28,-23,30,-94,-37,82,-38, 7,88,93,79,-27,-58,60,124,-14,-79,45,-22,43, 
};
const TfArray<4, int> tensor_dimension11 = { 4, { 8,1,3,13 } };
const TfArray<8, float> quant11_scale = { 8, { 0.0026137304957956076, 0.0027024934533983469, 0.0026916549541056156, 0.0026323273777961731, 0.0023565993178635836, 0.0026326104998588562, 0.0024085922632366419, 0.0026289517991244793, } };
const TfArray<8, int> quant11_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,1,55,13 } };
const TfArray<1, float> quant12_scale = { 1, { 0.031775142997503281, } };
const TfArray<1, int> quant12_zero = { 1, { -3 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,1,55,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.015392173081636429, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,55,1,8 } };
const TfArray<1, float> quant14_scale = { 1, { 0.015392173081636429, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<4, int> tensor_dimension15 = { 4, { 1,28,1,8 } };
const TfArray<1, float> quant15_scale = { 1, { 0.015392173081636429, } };
const TfArray<1, int> quant15_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,28,8 } };
const TfArray<1, float> quant16_scale = { 1, { 0.015392173081636429, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,28,16 } };
const TfArray<1, float> quant17_scale = { 1, { 0.016338741406798363, } };
const TfArray<1, int> quant17_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<4, int> tensor_dimension18 = { 4, { 1,28,1,16 } };
const TfArray<1, float> quant18_scale = { 1, { 0.016338741406798363, } };
const TfArray<1, int> quant18_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<4, int> tensor_dimension19 = { 4, { 1,14,1,16 } };
const TfArray<1, float> quant19_scale = { 1, { 0.016338741406798363, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<2, int> tensor_dimension20 = { 2, { 1,224 } };
const TfArray<1, float> quant20_scale = { 1, { 0.016338741406798363, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<2, int> tensor_dimension21 = { 2, { 1,4 } };
const TfArray<1, float> quant21_scale = { 1, { 0.074700124561786652, } };
const TfArray<1, int> quant21_zero = { 1, { 3 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<2, int> tensor_dimension22 = { 2, { 1,4 } };
const TfArray<1, float> quant22_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,1 } };
const TfArray<1, int> outputs0 = { 1, { 12 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 12,11,10 } };
const TfArray<1, int> outputs1 = { 1, { 13 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 13,2 } };
const TfArray<1, int> outputs2 = { 1, { 14 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 14 } };
const TfArray<1, int> outputs3 = { 1, { 15 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 15,3 } };
const TfArray<1, int> outputs4 = { 1, { 16 } };
const TfLiteConvParams opdata5 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs5 = { 3, { 16,9,8 } };
const TfArray<1, int> outputs5 = { 1, { 17 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 17,4 } };
const TfArray<1, int> outputs6 = { 1, { 18 } };
const TfLitePoolParams opdata7 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs7 = { 1, { 18 } };
const TfArray<1, int> outputs7 = { 1, { 19 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 19,5 } };
const TfArray<1, int> outputs8 = { 1, { 20 } };
const TfLiteFullyConnectedParams opdata9 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs9 = { 3, { 20,7,6 } };
const TfArray<1, int> outputs9 = { 1, { 21 } };
const TfLiteSoftmaxParams opdata10 = { 1 };
const TfArray<1, int> inputs10 = { 1, { 21 } };
const TfArray<1, int> outputs10 = { 1, { 22 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 720, (TfLiteIntArray*)&tensor_dimension0, 715, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 896, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 312, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 715, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 720, (TfLiteIntArray*)&tensor_dimension13, 440, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 440, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 448, (TfLiteIntArray*)&tensor_dimension15, 224, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 224, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 448, (TfLiteIntArray*)&tensor_dimension17, 448, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 448, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 448, (TfLiteIntArray*)&tensor_dimension19, 224, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 224, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 224, (TfLiteIntArray*)&tensor_dimension21, 4, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 4, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_SOFTMAX, },
};

static void init_tflite_tensor(size_t i, TfLiteTensor *tensor) {
  tensor->type = tensorData[i].type;
  tensor->is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  tensor->allocation_type = tensorData[i].allocation_type;
#else
  tensor->allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
  tensor->bytes = tensorData[i].bytes;
  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  if(tensor->allocation_type == kTfLiteArenaRw){
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
      tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
  tensor->quantization = tensorData[i].quantization;
  if (tensor->quantization.type == kTfLiteAffineQuantization) {
    TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
    tensor->params.scale = quant->scale->data[0];
    tensor->params.zero_point = quant->zero_point->data[0];
  }

}

static void init_tflite_eval_tensor(int i, TfLiteEvalTensor *tensor) {

  tensor->type = tensorData[i].type;

  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  auto allocation_type = tensorData[i].allocation_type;
  if(allocation_type == kTfLiteArenaRw) {
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
    tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
}

static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBufferImpl(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  uint32_t align_bytes = (bytes % 16) ? 16 - (bytes % 16) : 0;

  if (current_location - (bytes + align_bytes) < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  // align to the left aligned boundary of 16 bytes
  current_location -= 15; // for alignment
  current_location += 16 - ((uintptr_t)(current_location) & 15);

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArenaImpl(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBufferImpl(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBufferImpl(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static const uint16_t TENSOR_IX_UNUSED = 0x7FFF;

static void ResetTensors() {
  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    tflTensors[ix].index = TENSOR_IX_UNUSED;
  }
  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    tflEvalTensors[ix].index = TENSOR_IX_UNUSED;
  }
}

static TfLiteTensor* GetTensorImpl(const struct TfLiteContext* context,
                               int tensor_idx) {

  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    // already used? OK!
    if (tflTensors[ix].index == tensor_idx) {
      return &tflTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_tensor(tensor_idx, &tflTensors[ix].tensor);
      tflTensors[ix].index = tensor_idx;
      return &tflTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_TENSOR_COUNT (%d)\n", MAX_TFL_TENSOR_COUNT);
  return nullptr;
}

static TfLiteEvalTensor* GetEvalTensorImpl(const struct TfLiteContext* context,
                                       int tensor_idx) {

  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    // already used? OK!
    if (tflEvalTensors[ix].index == tensor_idx) {
      return &tflEvalTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflEvalTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_eval_tensor(tensor_idx, &tflEvalTensors[ix].tensor);
      tflEvalTensors[ix].index = tensor_idx;
      return &tflEvalTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_EVAL_COUNT (%d)\n", (int)MAX_TFL_EVAL_COUNT);
  return nullptr;
}

class EonMicroContext : public MicroContext {
 public:
  EonMicroContext(): MicroContext(nullptr, nullptr, nullptr) { }

  void* AllocatePersistentBuffer(size_t bytes) {
    return AllocatePersistentBufferImpl(nullptr, bytes);
  };
  TfLiteStatus RequestScratchBufferInArena(size_t bytes,
                                           int* buffer_index) {
  return RequestScratchBufferInArenaImpl(nullptr, bytes, buffer_index);
  }
  void* GetScratchBuffer(int buffer_index) {
    return GetScratchBufferImpl(nullptr, buffer_index);
  }

  TfLiteTensor* AllocateTempTfLiteTensor(int tensor_index) {
    return GetTensorImpl(nullptr, tensor_index);
  }
  void DeallocateTempTfLiteTensor(TfLiteTensor* tensor) {
    return;
  }
  bool IsAllTempTfLiteTensorDeallocated() {
    return true;
  }

  TfLiteEvalTensor* GetEvalTensor(int tensor_index) {
    return GetEvalTensorImpl(nullptr, tensor_index);
  }
};

} // namespace

TfLiteStatus tflite_learn_5_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;

  EonMicroContext micro_context_;
  ctx.impl_ = static_cast<void*>(&micro_context_);
  ctx.AllocatePersistentBuffer = &AllocatePersistentBufferImpl;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArenaImpl;
  ctx.GetScratchBuffer = &GetScratchBufferImpl;
  ctx.GetTensor = &GetTensorImpl;
  ctx.GetEvalTensor = &GetEvalTensorImpl;
  ctx.tensors_size = 23;
  for (size_t i = 0; i < 23; ++i) {
    TfLiteTensor tensor;
    init_tflite_tensor(i, &tensor);
    if (tensor.allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tensor.data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t i = 0; i < 11; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for (size_t i = 0; i < 11; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      ResetTensors();

      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteStatus tflite_learn_5_input(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(inTensorIndices[index], tensor);
  return kTfLiteOk;
}

static const int outTensorIndices[] = {
  22, 
};
TfLiteStatus tflite_learn_5_output(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(outTensorIndices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_5_invoke() {
  for (size_t i = 0; i < 11; ++i) {
    ResetTensors();

    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_5_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}
