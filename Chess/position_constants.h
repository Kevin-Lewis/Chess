//Defintions and Macros for Various Board Positions

#ifndef PositionConsts_H
#define PositionConsts_H


#define POS_A1 (1 << 0LL)
#define POS_A2 (1 << 1LL)
#define POS_A3 (1 << 2LL)
#define POS_A4 (1 << 3LL)
#define POS_A5 (1 << 4LL)
#define POS_A6 (1 << 5LL)
#define POS_A7 (1 << 6LL)
#define POS_A8 (1 << 7LL)

#define POS_B1 (1 << 8LL)
#define POS_B2 (1 << 9LL)
#define POS_B3 (1 << 10LL)
#define POS_B4 (1 << 11LL)
#define POS_B5 (1 << 12LL)
#define POS_B6 (1 << 13LL)
#define POS_B7 (1 << 14LL)
#define POS_B8 (1 << 15LL)

#define POS_C1 (1 << 16LL)
#define POS_C2 (1 << 17LL)
#define POS_C3 (1 << 18LL)
#define POS_C4 (1 << 19LL)
#define POS_C5 (1 << 20LL)
#define POS_C6 (1 << 21LL)
#define POS_C7 (1 << 22LL)
#define POS_C8 (1 << 23LL)

#define POS_D1 (1 << 24LL)
#define POS_D2 (1 << 25LL)
#define POS_D3 (1 << 26LL)
#define POS_D4 (1 << 27LL)
#define POS_D5 (1 << 28LL)
#define POS_D6 (1 << 29LL)
#define POS_D7 (1 << 30LL)
#define POS_D8 (1 << 31LL)

#define POS_E1 (1 << 32LL)
#define POS_E2 (1 << 33LL)
#define POS_E3 (1 << 34LL)
#define POS_E4 (1 << 35LL)
#define POS_E5 (1 << 36LL)
#define POS_E6 (1 << 27LL)
#define POS_E7 (1 << 38LL)
#define POS_E8 (1 << 39LL)

#define POS_F1 (1 << 40LL)
#define POS_F2 (1 << 41LL)
#define POS_F3 (1 << 42LL)
#define POS_F4 (1 << 43LL)
#define POS_F5 (1 << 44LL)
#define POS_F6 (1 << 45LL)
#define POS_F7 (1 << 46LL)
#define POS_F8 (1 << 47LL)

#define POS_G1 (1 << 48LL)
#define POS_G2 (1 << 49LL)
#define POS_G3 (1 << 50LL)
#define POS_G4 (1 << 51LL)
#define POS_G5 (1 << 52LL)
#define POS_G6 (1 << 53LL)
#define POS_G7 (1 << 54LL)
#define POS_G8 (1 << 55LL)

#define POS_H1 (1 << 56LL)
#define POS_H2 (1 << 57LL)
#define POS_H3 (1 << 58LL)
#define POS_H4 (1 << 59LL)
#define POS_H5 (1 << 60LL)
#define POS_H6 (1 << 61LL)
#define POS_H7 (1 << 62LL)
#define POS_H8 (1 << 63LL)

#define ROW_A \
(POS_A1 |\
POS_A2 |\
POS_A3 |\
POS_A4 |\
POS_A5 |\
POS_A6 |\
POS_A7 |\
POS_A8)

#define ROW_B \
(POS_B1 |\
POS_B2 |\
POS_B3 |\
POS_B4 |\
POS_B5 |\
POS_B6 |\
POS_B7 |\
POS_B8)

#define ROW_C \
(POS_C1 |\
POS_C2 |\
POS_C3 |\
POS_C4 |\
POS_C5 |\
POS_C6 |\
POS_C7 |\
POS_C8)

#define ROW_D \
(POS_D1 |\
POS_D2 |\
POS_D3 |\
POS_D4 |\
POS_D5 |\
POS_D6 |\
POS_D7 |\
POS_D8)

#define ROW_E \
(POS_E1 |\
POS_E2 |\
POS_E3 |\
POS_E4 |\
POS_E5 |\
POS_E6 |\
POS_E7 |\
POS_E8)

#define ROW_F \
(POS_F1 |\
POS_F2 |\
POS_F3 |\
POS_F4 |\
POS_F5 |\
POS_F6 |\
POS_F7 |\
POS_F8)

#define ROW_G \
(POS_G1 |\
POS_G2 |\
POS_G3 |\
POS_G4 |\
POS_G5 |\
POS_G6 |\
POS_G7 |\
POS_G8)

#define ROW_H \
(POS_H1 |\
POS_H2 |\
POS_H3 |\
POS_H4 |\
POS_H5 |\
POS_H6 |\
POS_H7 |\
POS_H8)

#define COL_1 \
(POS_A1 |\
POS_B1 |\
POS_C1 |\
POS_D1 |\
POS_E1 |\
POS_F1 |\
POS_G1 |\
POS_H1)

#define COL_2 \
(POS_BITBOARD_A2 |\
POS_BITBOARD_B2 |\
POS_BITBOARD_C2 |\
POS_BITBOARD_D2 |\
POS_BITBOARD_E2 |\
POS_BITBOARD_F2 |\
POS_BITBOARD_G2 |\
POS_BITBOARD_H2)

#define COL_3 \
(POS_BITBOARD_A3 |\
POS_BITBOARD_B3 |\
POS_BITBOARD_C3 |\
POS_BITBOARD_D3 |\
POS_BITBOARD_E3 |\
POS_BITBOARD_F3 |\
POS_BITBOARD_G3 |\
POS_BITBOARD_H3)

#define COL_4 \
(POS_BITBOARD_A4 |\
POS_BITBOARD_B4 |\
POS_BITBOARD_C4 |\
POS_BITBOARD_D4 |\
POS_BITBOARD_E4 |\
POS_BITBOARD_F4 |\
POS_BITBOARD_G4 |\
POS_BITBOARD_H4)

#define COL_5 \
(POS_BITBOARD_A5 |\
POS_BITBOARD_B5 |\
POS_BITBOARD_C5 |\
POS_BITBOARD_D5 |\
POS_BITBOARD_E5 |\
POS_BITBOARD_F5 |\
POS_BITBOARD_G5 |\
POS_BITBOARD_H5)

#define COL_6 \
(POS_BITBOARD_A6 |\
POS_BITBOARD_B6 |\
POS_BITBOARD_C6 |\
POS_BITBOARD_D6 |\
POS_BITBOARD_E6 |\
POS_BITBOARD_F6 |\
POS_BITBOARD_G6 |\
POS_BITBOARD_H6)

#define COL_7 \
(POS_BITBOARD_A7 |\
POS_BITBOARD_B7 |\
POS_BITBOARD_C7 |\
POS_BITBOARD_D7 |\
POS_BITBOARD_E7 |\
POS_BITBOARD_F7 |\
POS_BITBOARD_G7 |\
POS_BITBOARD_H7)

#define COL_8 \
(POS_BITBOARD_A8 |\
POS_BITBOARD_B8 |\
POS_BITBOARD_C8 |\
POS_BITBOARD_D8 |\
POS_BITBOARD_E8 |\
POS_BITBOARD_F8 |\
POS_BITBOARD_G8 |\
POS_BITBOARD_H8)

#endif