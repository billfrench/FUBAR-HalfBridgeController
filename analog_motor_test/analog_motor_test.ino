#include <TimerOne.h>

const byte LOW_SIDE_OUT = 14;
const byte HIGH_SIDE_OUT = 15;
const byte THROTTLE_IN_PIN = 21;
const byte FUSE_IN_PIN = A3;

int FUSE_SHUNT_READING = 0;
int OUTPUT_PWM = 0;

const int AMP_CUTOUT = 370; //645 //250 //379
const int CUTOUT_PWM = 50;

//AMPS  AnalogRead  +512 for LT1999 where 512 = zero amps
//40    114.41232   626.41232
//45    128.71386   640.71386
//50    143.0154    655.0154
//55    157.31694   669.31694
//60    171.61848   683.61848

const int ThrottleLUT[1025] = {
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  13,
  13,
  13,
  13,
  13,
  13,
  14,
  14,
  14,
  14,
  14,
  14,
  15,
  15,
  15,
  15,
  15,
  15,
  16,
  16,
  16,
  16,
  16,
  16,
  17,
  17,
  17,
  17,
  17,
  18,
  18,
  18,
  18,
  18,
  19,
  19,
  19,
  19,
  19,
  20,
  20,
  20,
  20,
  21,
  21,
  21,
  21,
  21,
  22,
  22,
  22,
  22,
  23,
  23,
  23,
  23,
  24,
  24,
  24,
  24,
  24,
  25,
  25,
  25,
  25,
  26,
  26,
  26,
  27,
  27,
  27,
  27,
  28,
  28,
  28,
  28,
  29,
  29,
  29,
  29,
  30,
  30,
  30,
  31,
  31,
  31,
  31,
  32,
  32,
  32,
  33,
  33,
  33,
  34,
  34,
  34,
  34,
  35,
  35,
  35,
  36,
  36,
  36,
  37,
  37,
  37,
  38,
  38,
  38,
  39,
  39,
  39,
  40,
  40,
  40,
  41,
  41,
  41,
  42,
  42,
  42,
  43,
  43,
  44,
  44,
  44,
  45,
  45,
  45,
  46,
  46,
  46,
  47,
  47,
  48,
  48,
  48,
  49,
  49,
  50,
  50,
  50,
  51,
  51,
  52,
  52,
  52,
  53,
  53,
  54,
  54,
  54,
  55,
  55,
  56,
  56,
  57,
  57,
  58,
  58,
  58,
  59,
  59,
  60,
  60,
  61,
  61,
  62,
  62,
  62,
  63,
  63,
  64,
  64,
  65,
  65,
  66,
  66,
  67,
  67,
  68,
  68,
  69,
  69,
  70,
  70,
  71,
  71,
  72,
  72,
  73,
  73,
  74,
  74,
  75,
  75,
  76,
  76,
  77,
  77,
  78,
  78,
  79,
  80,
  80,
  81,
  81,
  82,
  82,
  83,
  83,
  84,
  85,
  85,
  86,
  86,
  87,
  87,
  88,
  89,
  89,
  90,
  90,
  91,
  92,
  92,
  93,
  93,
  94,
  95,
  95,
  96,
  96,
  97,
  98,
  98,
  99,
  100,
  100,
  101,
  101,
  102,
  103,
  103,
  104,
  105,
  105,
  106,
  107,
  107,
  108,
  109,
  109,
  110,
  111,
  111,
  112,
  113,
  113,
  114,
  115,
  115,
  116,
  117,
  118,
  118,
  119,
  120,
  120,
  121,
  122,
  123,
  123,
  124,
  125,
  126,
  126,
  127,
  128,
  128,
  129,
  130,
  131,
  132,
  132,
  133,
  134,
  135,
  135,
  136,
  137,
  138,
  138,
  139,
  140,
  141,
  142,
  142,
  143,
  144,
  145,
  146,
  147,
  147,
  148,
  149,
  150,
  151,
  152,
  152,
  153,
  154,
  155,
  156,
  157,
  157,
  158,
  159,
  160,
  161,
  162,
  163,
  164,
  164,
  165,
  166,
  167,
  168,
  169,
  170,
  171,
  172,
  173,
  173,
  174,
  175,
  176,
  177,
  178,
  179,
  180,
  181,
  182,
  183,
  184,
  185,
  186,
  187,
  188,
  189,
  189,
  190,
  191,
  192,
  193,
  194,
  195,
  196,
  197,
  198,
  199,
  200,
  201,
  202,
  203,
  204,
  205,
  206,
  208,
  209,
  210,
  211,
  212,
  213,
  214,
  215,
  216,
  217,
  218,
  219,
  220,
  221,
  222,
  223,
  225,
  226,
  227,
  228,
  229,
  230,
  231,
  232,
  233,
  234,
  236,
  237,
  238,
  239,
  240,
  241,
  242,
  244,
  245,
  246,
  247,
  248,
  249,
  250,
  252,
  253,
  254,
  255,
  256,
  258,
  259,
  260,
  261,
  262,
  264,
  265,
  266,
  267,
  268,
  270,
  271,
  272,
  273,
  275,
  276,
  277,
  278,
  280,
  281,
  282,
  283,
  285,
  286,
  287,
  289,
  290,
  291,
  292,
  294,
  295,
  296,
  298,
  299,
  300,
  302,
  303,
  304,
  306,
  307,
  308,
  310,
  311,
  312,
  314,
  315,
  317,
  318,
  319,
  321,
  322,
  323,
  325,
  326,
  328,
  329,
  330,
  332,
  333,
  335,
  336,
  338,
  339,
  340,
  342,
  343,
  345,
  346,
  348,
  349,
  351,
  352,
  353,
  355,
  356,
  358,
  359,
  361,
  362,
  364,
  365,
  367,
  368,
  370,
  371,
  373,
  375,
  376,
  378,
  379,
  381,
  382,
  384,
  385,
  387,
  389,
  390,
  392,
  393,
  395,
  396,
  398,
  400,
  401,
  403,
  404,
  406,
  408,
  409,
  411,
  413,
  414,
  416,
  417,
  419,
  421,
  422,
  424,
  426,
  427,
  429,
  431,
  432,
  434,
  436,
  438,
  439,
  441,
  443,
  444,
  446,
  448,
  450,
  451,
  453,
  455,
  457,
  458,
  460,
  462,
  464,
  465,
  467,
  469,
  471,
  472,
  474,
  476,
  478,
  480,
  481,
  483,
  485,
  487,
  489,
  491,
  492,
  494,
  496,
  498,
  500,
  502,
  504,
  505,
  507,
  509,
  511,
  513,
  515,
  517,
  519,
  521,
  522,
  524,
  526,
  528,
  530,
  532,
  534,
  536,
  538,
  540,
  542,
  544,
  546,
  548,
  550,
  552,
  554,
  556,
  558,
  560,
  562,
  564,
  566,
  568,
  570,
  572,
  574,
  576,
  578,
  580,
  582,
  584,
  586,
  588,
  590,
  592,
  594,
  597,
  599,
  601,
  603,
  605,
  607,
  609,
  611,
  613,
  616,
  618,
  620,
  622,
  624,
  626,
  628,
  631,
  633,
  635,
  637,
  639,
  642,
  644,
  646,
  648,
  650,
  653,
  655,
  657,
  659,
  662,
  664,
  666,
  668,
  671,
  673,
  675,
  677,
  680,
  682,
  684,
  686,
  689,
  691,
  693,
  696,
  698,
  700,
  703,
  705,
  707,
  710,
  712,
  714,
  717,
  719,
  722,
  724,
  726,
  729,
  731,
  733,
  736,
  738,
  741,
  743,
  746,
  748,
  750,
  753,
  755,
  758,
  760,
  763,
  765,
  768,
  770,
  773,
  775,
  778,
  780,
  783,
  785,
  788,
  790,
  793,
  795,
  798,
  800,
  803,
  805,
  808,
  810,
  813,
  816,
  818,
  821,
  823,
  826,
  829,
  831,
  834,
  836,
  839,
  842,
  844,
  847,
  850,
  852,
  855,
  858,
  860,
  863,
  866,
  868,
  871,
  874,
  876,
  879,
  882,
  884,
  887,
  890,
  893,
  895,
  898,
  901,
  904,
  906,
  909,
  912,
  915,
  917,
  920,
  923,
  926,
  929,
  931,
  934,
  937,
  940,
  943,
  946,
  948,
  951,
  954,
  957,
  960,
  963,
  966,
  969,
  971,
  974,
  977,
  980,
  983,
  986,
  989,
  992,
  995,
  998,
  1001,
  1004,
  1007,
  1010,
  1013,
  1016,
  1019,
  1022,
  1024
};

