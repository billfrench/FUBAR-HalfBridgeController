#include <TimerOne.h>

int LOW_OUT = 14;
int HIGH_OUT = 15;
int THROTTLE_IN_PIN = 21;
int FUSE_IN = A3;

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
  9,
  10,
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
  15,
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
  20,
  21,
  21,
  21,
  21,
  22,
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
  25,
  25,
  25,
  25,
  26,
  26,
  26,
  26,
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
  32,
  32,
  32,
  32,
  33,
  33,
  33,
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
  43,
  43,
  43,
  44,
  44,
  45,
  45,
  45,
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
  51,
  51,
  51,
  52,
  52,
  53,
  53,
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
  59,
  59,
  60,
  60,
  61,
  61,
  62,
  62,
  63,
  63,
  64,
  64,
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
  71,
  71,
  72,
  72,
  73,
  74,
  74,
  75,
  75,
  76,
  77,
  77,
  78,
  79,
  79,
  80,
  81,
  81,
  82,
  82,
  83,
  84,
  84,
  85,
  86,
  87,
  87,
  88,
  89,
  89,
  90,
  91,
  91,
  92,
  93,
  94,
  94,
  95,
  96,
  97,
  97,
  98,
  99,
  100,
  100,
  101,
  102,
  103,
  104,
  104,
  105,
  106,
  107,
  108,
  108,
  109,
  110,
  111,
  112,
  113,
  114,
  114,
  115,
  116,
  117,
  118,
  119,
  120,
  121,
  121,
  122,
  123,
  124,
  125,
  126,
  127,
  128,
  129,
  130,
  131,
  132,
  133,
  134,
  135,
  136,
  137,
  138,
  139,
  140,
  141,
  142,
  143,
  144,
  145,
  146,
  147,
  148,
  149,
  150,
  151,
  152,
  153,
  154,
  156,
  157,
  158,
  159,
  160,
  161,
  162,
  163,
  165,
  166,
  167,
  168,
  169,
  170,
  172,
  173,
  174,
  175,
  176,
  178,
  179,
  180,
  181,
  183,
  184,
  185,
  186,
  188,
  189,
  190,
  192,
  193,
  194,
  196,
  197,
  198,
  200,
  201,
  202,
  204,
  205,
  206,
  208,
  209,
  211,
  212,
  213,
  215,
  216,
  218,
  219,
  221,
  222,
  224,
  225,
  227,
  228,
  230,
  231,
  233,
  234,
  236,
  237,
  239,
  240,
  242,
  243,
  245,
  247,
  248,
  250,
  252,
  253,
  255,
  256,
  258,
  260,
  261,
  263,
  265,
  266,
  268,
  270,
  272,
  273,
  275,
  277,
  279,
  280,
  282,
  284,
  286,
  288,
  289,
  291,
  293,
  295,
  297,
  299,
  300,
  302,
  304,
  306,
  308,
  310,
  312,
  314,
  316,
  318,
  320,
  322,
  324,
  326,
  328,
  330,
  332,
  334,
  336,
  338,
  340,
  342,
  344,
  346,
  348,
  350,
  352,
  354,
  357,
  359,
  361,
  363,
  365,
  367,
  370,
  372,
  374,
  376,
  379,
  381,
  383,
  385,
  388,
  390,
  392,
  395,
  397,
  399,
  402,
  404,
  406,
  409,
  411,
  414,
  416,
  418,
  421,
  423,
  426,
  428,
  431,
  433,
  436,
  438,
  441,
  443,
  446,
  449,
  451,
  454,
  456,
  459,
  462,
  464,
  467,
  470,
  472,
  475,
  478,
  480,
  483,
  486,
  489,
  491,
  494,
  497,
  500,
  503,
  506,
  508,
  511,
  514,
  517,
  520,
  523,
  526,
  529,
  532,
  535,
  538,
  541,
  544,
  547,
  550,
  553,
  556,
  559,
  562,
  565,
  568,
  571,
  574,
  577,
  581,
  584,
  587,
  590,
  593,
  597,
  600,
  603,
  606,
  610,
  613,
  616,
  620,
  623,
  626,
  630,
  633,
  637,
  640,
  643,
  647,
  650,
  654,
  657,
  661,
  664,
  668,
  672,
  675,
  679,
  682,
  686,
  690,
  693,
  697,
  701,
  704,
  708,
  712,
  715,
  719,
  723,
  727,
  731,
  734,
  738,
  742,
  746,
  750,
  754,
  758,
  762,
  766,
  770,
  773,
  777,
  782,
  786,
  790,
  794,
  798,
  802,
  806,
  810,
  814,
  818,
  823,
  827,
  831,
  835,
  840,
  844,
  848,
  852,
  857,
  861,
  865,
  870,
  874,
  879,
  883,
  887,
  892,
  896,
  901,
  905,
  910,
  915,
  919,
  924,
  928,
  933,
  938,
  942,
  947,
  952,
  956,
  961,
  966,
  971,
  975,
  980,
  985,
  990,
  995,
  1000,
  1005,
  1010,
  1015,
  1020,
  1024
};

