/* Atomic Text - Text scrolling for M5Atom
 * Copyright (C) 2020 Silent Software (Benjamin Brown)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

extern const bool WHITESPACE[30] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
extern const bool A[30] = {true,true,true,true,true,false,true,false,false,false,true,false,true,false,false,false,true,false,true,true,true,true,true,false,true,false,false,false,true,false};
extern const bool B[30] = {true,true,true,true,false,false,true,false,false,false,true,false,true,true,true,true,false,false,true,false,false,false,true,false,true,true,true,true,false,false};
extern const bool C[30] = {true,true,true,true,true,false,true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,true,true,true,true,false};
extern const bool D[30] = {true,true,true,true,false,false,true,false,false,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false,true,true,true,true,false,false};
extern const bool E[30] = {true,true,true,true,true,false,true,false,false,false,false,false,true,true,true,true,false,false,true,false,false,false,false,false,true,true,true,true,true,false};
extern const bool F[30] = {true,true,true,true,true,false,true,false,false,false,false,false,true,true,true,true,false,false,true,false,false,false,false,false,true,false,false,false,false,false};
extern const bool G[30] = {true,true,true,true,true,false,true,false,false,false,false,false,true,false,false,true,true,false,true,false,false,false,true,false,true,true,true,true,true,false};
extern const bool H[30] = {true,false,false,false,true,false,true,false,false,false,true,false,true,true,true,true,true,false,true,false,false,false,true,false,true,false,false,false,true,false};
extern const bool I[30] = {true,true,true,true,true,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false,true,true,true,true,true,false};
extern const bool J[30] = {false,false,false,true,true,false,false,false,false,false,true,false,false,false,false,false,true,false,true,false,false,false,true,false,true,true,true,true,true,false};
extern const bool K[30] = {true,false,false,false,true,false,true,false,false,true,false,false,true,true,true,false,false,false,true,false,false,true,false,false,true,false,false,false,true,false};
extern const bool L[30] = {true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,true,true,true,true,false};
extern const bool M[30] = {true,false,false,false,true,false,true,true,false,true,true,false,true,false,true,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false};
extern const bool N[30] = {true,false,false,false,true,false,true,true,false,false,true,false,true,false,true,false,true,false,true,false,false,true,true,false,true,false,false,false,true,false};
extern const bool O[30] = {false,true,true,true,false,false,true,false,false,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false,false,true,true,true,false,false};
extern const bool P[30] = {true,true,true,true,false,false,true,false,false,false,true,false,true,true,true,true,false,false,true,false,false,false,false,false,true,false,false,false,false,false};
extern const bool Q[30] = {true,true,true,true,true,false,true,false,false,false,true,false,true,false,false,false,true,false,true,true,true,true,true,false,false,false,true,false,false,false};
extern const bool R[30] = {true,true,true,true,false,false,true,false,false,false,true,false,true,true,true,true,false,false,true,false,false,false,true,false,true,false,false,false,true,false};
extern const bool S[30] = {true,true,true,true,true,false,true,false,false,false,false,false,true,true,true,true,true,false,false,false,false,false,true,false,true,true,true,true,true,false};
extern const bool T[30] = {true,true,true,true,true,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false};
extern const bool U[30] = {true,false,false,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false,true,true,true,true,true,false};
extern const bool V[30] = {true,false,false,false,true,false,true,false,false,false,true,false,false,true,false,true,false,false,false,true,false,true,false,false,false,false,true,false,false,false};
extern const bool W[30] = {true,false,false,false,true,false,true,false,false,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,false,true,false,true,false,false};
extern const bool X[30] = {true,false,false,false,true,false,false,true,false,true,false,false,false,false,true,false,false,false,false,true,false,true,false,false,true,false,false,false,true,false};
extern const bool Y[30] = {true,false,false,false,true,false,true,false,false,false,true,false,false,true,false,true,false,false,false,false,true,false,false,false,false,false,true,false,false,false};
extern const bool Z[30] = {true,true,true,true,true,false,false,false,false,true,false,false,false,false,true,false,false,false,false,true,false,false,false,false,true,true,true,true,true,false};
extern const bool ONE[30] = {false,true,false,false,false,false,true,true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false,false,true,true,true,false,false,false};
extern const bool TWO[30] = {true,true,true,true,false,false,false,false,false,false,true,false,false,true,true,true,false,false,true,false,false,false,false,false,true,true,true,true,true,false};
extern const bool THREE[30] = {true,true,true,true,true,false,false,false,false,false,true,false,false,true,true,true,false,false,false,false,false,false,true,false,true,true,true,true,true,false};
extern const bool FOUR[30] = {true,false,false,false,false,false,true,false,false,false,false,false,true,false,true,false,false,false,true,true,true,true,true,false,false,false,true,false,false,false};
extern const bool FIVE[30] = {true,true,true,true,true,false,true,false,false,false,false,false,true,true,true,true,false,false,false,false,false,false,true,false,true,true,true,true,false,false};
extern const bool SIX[30] = {true,true,true,true,true,false,true,false,false,false,false,false,true,true,true,true,true,false,true,false,false,false,true,false,true,true,true,true,true,false};
extern const bool SEVEN[30] = {true,true,true,true,true,false,false,false,false,false,true,false,false,false,false,true,false,false,false,false,true,false,false,false,false,false,true,false,false,false};
extern const bool EIGHT[30] = {true,true,true,true,true,false,true,false,false,false,true,false,true,true,true,true,true,false,true,false,false,false,true,false,true,true,true,true,true,false};
extern const bool NINE[30] = {true,true,true,true,true,false,true,false,false,false,true,false,true,true,true,true,true,false,false,false,false,false,true,false,true,true,true,true,true,false};
extern const bool ZERO[30] = {true,true,true,true,true,false,true,false,false,true,true,false,true,false,true,false,true,false,true,true,false,false,true,false,true,true,true,true,true,false};
extern const bool SPEECHMARK[30] = {false,false,true,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
extern const bool EXCLAMATION[30] = {false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,true,false,false,false};
extern const bool QUESTIONMARK[30] = {false,false,true,true,false,false,false,true,false,false,true,false,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,true,false,false};
extern const bool AT[30] = {true,true,true,true,true,false,true,false,false,false,true,false,true,false,true,true,true,false,true,false,false,false,false,false,true,true,true,true,true,false};
extern const bool DOLLAR[30] = {true,true,true,true,true,false,true,false,true,false,false,false,true,true,true,true,true,false,false,false,true,false,true,false,true,true,true,true,true,false};
extern const bool DASH[30] = {false,false,false,false,false,false,false,false,false,false,false,false,true,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false};
extern const bool PERCENTAGE[30] = {true,false,false,false,true,false,false,false,false,true,false,false,false,false,true,false,false,false,false,true,false,false,false,false,true,false,false,false,true,false};
extern const bool PLUS[30] = {false,false,true,false,false,false,false,false,true,false,false,false,true,true,true,true,true,false,false,false,true,false,false,false,false,false,true,false,false,false};
extern const bool EQUALS[30] = {false,false,false,false,false,false,true,true,true,true,true,false,false,false,false,false,false,false,true,true,true,true,true,false,false,false,false,false,false,false};
extern const bool OCTOTHORPE[30] = {false,true,false,true,false,false,true,true,true,true,true,false,false,true,false,true,false,false,true,true,true,true,true,false,false,true,false,true,false,false};
extern const bool UNDERSCORE[30] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,true,true,true,true};
extern const bool AMPERSAND[30] = {false,true,true,false,false,false,true,false,false,false,false,false,false,true,true,false,true,false,true,false,false,true,false,false,false,true,true,false,true,false};
extern const bool QUOTE[30] = {false,false,true,false,false,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
