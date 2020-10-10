/******************************************************************************



                            Online C Compiler.

                Code, Compile, Run and Debug C program online.

Write your code in this editor and press "Run" button to compile and execute it.



*******************************************************************************/

#include <stdio.h>

#include <math.h>

#include "RES_TO_TEMP.h"

#include "define.h"

int temperature[] =

    {

        -30.0,

        -29.0,

        -28.0,

        -27.0,

        -26.0,

        -25.0,

        -24.0,

        -23.0,

        -22.0,

        -21.0,

        -20.0,

        -19.0,

        -18.0,

        -17.0,

        -16.0,

        -15.0,

        -14.0,

        -13.0,

        -12.0,

        -11.0,

        -10.0,

        -9.0,

        -8.0,

        -7.0,

        -6.0,

        -5.0,

        -4.0,

        -3.0,

        -2.0,

        -1.0,

        0.0,

        1.0,

        2.0,

        3.0,

        4.0,

        5.0,

        6.0,

        7.0,

        8.0,

        9.0,

        10.0,

        11.0,

        12.0,

        13.0,

        14.0,

        15.0,

        16.0,

        17.0,

        18.0,

        19.0,

        20.0,

        21.0,

        22.0,

        23.0,

        24.0,

        25.0,

        26.0,

        27.0,

        28.0,

        29.0,

        30.0,

        31.0,

        32.0,

        33.0,

        34.0,

        35.0,

        36.0,

        37.0,

        38.0,

        39.0,

        40.0,

        41.0,

        42.0,

        43.0,

        44.0,

        45.0,

        46.0,

        47.0,

        48.0,

        49.0,

        50.0,

        51.0,

        52.0,

        53.0,

        54.0,

        55.0,

        56.0,

        57.0,

        58.0,

        59.0,

        60.0,

        61.0,

        62.0,

        63.0,

        64.0,

        65.0,

        66.0,

        67.0,

        68.0,

        69.0,

        70.0,

        71.0,

        72.0,

        73.0,

        74.0,

        75.0,

        76.0,

        77.0,

        78.0,

        79.0,

        80.0,

        81.0,

        82.0,

        83.0,

        84.0,

        85.0,

        86.0,

        87.0,

        88.0,

        89.0,

        90.0,

        91.0,

        92.0,

        93.0,

        94.0,

        95.0,

        96.0,

        97.0,

        98.0,

        99.0,

        100.0,

        101.0,

        102.0,

        103.0,

        104.0,

        105.0

};

float resistans[] =

    {

        122.2915,

        115.6260,

        109.3808,

        103.5257,

        98.0331,

        92.8776,

        88.0357,

        83.4856,

        79.2075,

        75.1829,

        71.3947,

        67.8271,

        64.4657,

        61.2968,

        58.3079,

        55.4874,

        52.8246,

        50.3095,

        47.9327,

        45.6856,

        43.5601,

        41.5489,

        39.6449,

        37.8416,

        36.1331,

        34.5135,

        32.9778,

        31.5209,

        30.1383,

        28.8257,

        27.5790,

        26.3945,

        25.2686,

        24.1982,

        23.1800,

        22.2113,

        21.2891,

        20.4112,

        19.5749,

        18.7781,

        18.0187,

        17.2947,

        16.6042,

        15.9454,

        15.3168,

        14.7166,

        14.1436,

        13.5962,

        13.0733,

        12.5734,

        12.0956,

        11.6387,

        11.2016,

        10.7834,

        10.3831,

        10.0000,

        9.6331,

        9.2817,

        8.9450,

        8.5224,

        8.3132,

        8.0167,

        7.7323,

        7.4596,

        7.1979,

        6.9468,

        6.7057,

        6.4742,

        6.2519,

        6.0384,

        5.8333,

        5.6362,

        5.4467,

        5.2645,

        5.0894,

        4.9209,

        4.7588,

        4.5029,

        4.4528,

        4.3084,

        4.1693,

        4.0354,

        3.9064,

        3.7822,

        3.6625,

        3.5471,

        3.4359,

        3.3287,

        3.2254,

        3.1257,

        3.0296,

        2.9369,

        2.8474,

        2.7610,

        2.6777,

        2.5972,

        2.5196,

        2.4446,

        2.3721,

        2.3021,

        2.2345,

        2.1692,

        2.1060,

        2.0450,

        1.9860,

        1.9290,

        1.8738,

        1.8204,

        1.7688,

        1.7189,

        1.6706,

        1.6238,

        1.5786,

        1.5348,

        1.4924,

        1.4513,

        1.4115,

        1.3730,

        1.3357,

        1.2996,

        1.2646,

        1.2306,

        1.1977,

        1.1659,

        1.1349,

        1.1050,

        1.0759,

        1.0478,

        1.0204,

        0.9939,

        0.9682,

        0.9432,

        0.9190,

        0.8955,

        0.8727,

        0.8506

};

int get_temp(float num)

{
  float current_val = num / 1000;

  //   printf("\ncurrent_val %f",current_val);

  float pogresh = current_val / 100 * 2.5;

  int i;

  //     printf("\npogresh 2.5 %f",pogresh);

  for (i = 0; i < sizeof(resistans); i++)

  {
    if ((resistans[i] - current_val < 0.00001) ||
        (resistans[i] < (current_val + pogresh) &&
         resistans[i] > (current_val - pogresh))) {
      return temperature[i];
    }
  }
}

