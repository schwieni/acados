/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

#ifdef CODEGEN_PREFIX
  #define NAMESPACE_CONCAT(NS, ID) _NAMESPACE_CONCAT(NS, ID)
  #define _NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else /* CODEGEN_PREFIX */
  #define CASADI_PREFIX(ID) vde_hess_pendulum_ ## ID
#endif /* CODEGEN_PREFIX */

#include <math.h>

#ifndef real_t
#define real_t double
#endif /* real_t */

#define to_double(x) (double) x
#define to_int(x) (int) x
#define CASADI_CAST(x,y) (x) y
/* Pre-c99 compatibility */
#if __STDC_VERSION__ < 199901L
real_t CASADI_PREFIX(fmin)(real_t x, real_t y) { return x<y ? x : y;}
#define fmin(x,y) CASADI_PREFIX(fmin)(x,y)
real_t CASADI_PREFIX(fmax)(real_t x, real_t y) { return x>y ? x : y;}
#define fmax(x,y) CASADI_PREFIX(fmax)(x,y)
#endif

#define PRINTF printf
real_t CASADI_PREFIX(sq)(real_t x) { return x*x;}
#define sq(x) CASADI_PREFIX(sq)(x)

real_t CASADI_PREFIX(sign)(real_t x) { return x<0 ? -1 : x>0 ? 1 : x;}
#define sign(x) CASADI_PREFIX(sign)(x)

static const int CASADI_PREFIX(s0)[8] = {4, 1, 0, 4, 0, 1, 2, 3};
#define s0 CASADI_PREFIX(s0)
static const int CASADI_PREFIX(s1)[23] = {4, 4, 0, 4, 8, 12, 16, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
#define s1 CASADI_PREFIX(s1)
static const int CASADI_PREFIX(s2)[5] = {1, 1, 0, 1, 0};
#define s2 CASADI_PREFIX(s2)
static const int CASADI_PREFIX(s3)[9] = {5, 1, 0, 5, 0, 1, 2, 3, 4};
#define s3 CASADI_PREFIX(s3)
static const int CASADI_PREFIX(s4)[19] = {15, 1, 0, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
#define s4 CASADI_PREFIX(s4)
/* adjFun */
int adjFun(const real_t** arg, real_t** res, int* iw, real_t* w, int mem) {
  real_t a0=0.;
  if (res[0]!=0) res[0][0]=a0;
  a0=arg[3] ? arg[3][0] : 0;
  if (res[0]!=0) res[0][1]=a0;
  a0=arg[0] ? arg[0][2] : 0;
  real_t a1=cos(a0);
  real_t a2=1.0000000000000001e-01;
  a1=(a2*a1);
  real_t a3=cos(a0);
  real_t a4=(a1*a3);
  real_t a5=1.1000000000000001e+00;
  a5=(a5-a4);
  a4=8.0000000000000004e-01;
  real_t a6=(a4*a5);
  real_t a7=arg[3] ? arg[3][3] : 0;
  real_t a8=(a7/a6);
  real_t a9=1.0791000000000002e+01;
  real_t a10=(a9*a8);
  real_t a11=cos(a0);
  real_t a12=(a11*a10);
  real_t a13=arg[4] ? arg[4][0] : 0;
  real_t a14=(a13*a8);
  real_t a15=sin(a0);
  real_t a16=(a15*a14);
  a12=(a12-a16);
  a16=cos(a0);
  real_t a17=-8.0000000000000016e-02;
  a16=(a17*a16);
  real_t a18=arg[0] ? arg[0][3] : 0;
  real_t a19=(a18*a8);
  real_t a20=(a18*a19);
  real_t a21=(a16*a20);
  real_t a22=cos(a0);
  real_t a23=(a22*a21);
  a12=(a12+a23);
  a23=sin(a0);
  real_t a24=(a23*a20);
  a24=(a17*a24);
  real_t a25=sin(a0);
  real_t a26=(a25*a24);
  a12=(a12-a26);
  a26=(a16*a23);
  real_t a27=(a26*a18);
  real_t a28=(a27*a18);
  real_t a29=cos(a0);
  real_t a30=(a13*a29);
  a28=(a28+a30);
  a30=sin(a0);
  a30=(a9*a30);
  a28=(a28+a30);
  a28=(a28/a6);
  a30=(a28/a6);
  real_t a31=(a30*a7);
  a31=(a4*a31);
  real_t a32=sin(a0);
  a32=(a17*a32);
  real_t a33=(a32*a18);
  real_t a34=(a33*a18);
  real_t a35=cos(a0);
  real_t a36=9.8100000000000009e-01;
  a35=(a36*a35);
  real_t a37=sin(a0);
  real_t a38=(a35*a37);
  a34=(a34+a38);
  a34=(a34+a13);
  a34=(a34/a5);
  a38=(a34/a5);
  real_t a39=arg[3] ? arg[3][1] : 0;
  real_t a40=(a38*a39);
  a31=(a31+a40);
  a40=(a1*a31);
  real_t a41=sin(a0);
  real_t a42=(a41*a40);
  a12=(a12-a42);
  a42=(a3*a31);
  a42=(a2*a42);
  real_t a43=sin(a0);
  real_t a44=(a43*a42);
  a12=(a12-a44);
  a44=(a39/a5);
  real_t a45=(a35*a44);
  real_t a46=cos(a0);
  real_t a47=(a46*a45);
  a12=(a12+a47);
  a47=(a37*a44);
  a47=(a36*a47);
  real_t a48=sin(a0);
  real_t a49=(a48*a47);
  a12=(a12-a49);
  a49=(a18*a44);
  real_t a50=(a18*a49);
  a50=(a17*a50);
  real_t a51=cos(a0);
  real_t a52=(a51*a50);
  a12=(a12+a52);
  if (res[0]!=0) res[0][2]=a12;
  a12=(a27*a8);
  a52=(a26*a19);
  a12=(a12+a52);
  a52=arg[3] ? arg[3][2] : 0;
  a12=(a12+a52);
  a52=(a33*a44);
  a12=(a12+a52);
  a52=(a32*a49);
  a12=(a12+a52);
  if (res[0]!=0) res[0][3]=a12;
  a12=(a29*a8);
  a12=(a12+a44);
  if (res[0]!=0) res[0][4]=a12;
  a12=arg[1] ? arg[1][3] : 0;
  a52=(a19*a12);
  real_t a53=(a8*a12);
  real_t a54=(a8/a6);
  real_t a55=sin(a0);
  real_t a56=arg[1] ? arg[1][2] : 0;
  real_t a57=(a55*a56);
  a57=(a2*a57);
  real_t a58=(a3*a57);
  real_t a59=sin(a0);
  real_t a60=(a59*a56);
  real_t a61=(a1*a60);
  a58=(a58+a61);
  a61=(a4*a58);
  real_t a62=(a54*a61);
  real_t a63=(a18*a62);
  a53=(a53-a63);
  a63=(a18*a53);
  a52=(a52+a63);
  a63=(a16*a52);
  real_t a64=sin(a0);
  real_t a65=(a64*a56);
  a65=(a17*a65);
  real_t a66=(a20*a65);
  a63=(a63-a66);
  a63=(a22*a63);
  a66=sin(a0);
  real_t a67=(a66*a56);
  a67=(a21*a67);
  a63=(a63-a67);
  a67=sin(a0);
  real_t a68=(a67*a56);
  a68=(a10*a68);
  real_t a69=(a9*a62);
  a69=(a11*a69);
  a68=(a68+a69);
  a69=cos(a0);
  real_t a70=(a69*a56);
  a70=(a14*a70);
  real_t a71=(a13*a62);
  a71=(a15*a71);
  a70=(a70-a71);
  a68=(a68+a70);
  a63=(a63-a68);
  a68=cos(a0);
  a70=(a68*a56);
  a70=(a24*a70);
  a71=cos(a0);
  real_t a72=(a71*a56);
  real_t a73=(a20*a72);
  a52=(a23*a52);
  a73=(a73+a52);
  a73=(a17*a73);
  a73=(a25*a73);
  a70=(a70+a73);
  a63=(a63-a70);
  a70=cos(a0);
  a73=(a70*a56);
  a73=(a40*a73);
  a72=(a16*a72);
  a65=(a23*a65);
  a72=(a72-a65);
  a65=(a18*a72);
  a52=(a26*a12);
  a65=(a65+a52);
  a52=(a18*a65);
  real_t a74=(a27*a12);
  a52=(a52+a74);
  a74=sin(a0);
  real_t a75=(a74*a56);
  real_t a76=(a13*a75);
  a52=(a52-a76);
  a76=cos(a0);
  real_t a77=(a76*a56);
  a77=(a9*a77);
  a52=(a52+a77);
  a52=(a52/a6);
  a28=(a28/a6);
  a77=(a28*a61);
  a52=(a52-a77);
  a52=(a52/a6);
  a30=(a30/a6);
  a61=(a30*a61);
  a52=(a52-a61);
  a52=(a7*a52);
  a52=(a4*a52);
  a61=cos(a0);
  a77=(a61*a56);
  a77=(a17*a77);
  real_t a78=(a18*a77);
  real_t a79=(a32*a12);
  a78=(a78+a79);
  a79=(a18*a78);
  real_t a80=(a33*a12);
  a79=(a79+a80);
  a80=cos(a0);
  real_t a81=(a80*a56);
  real_t a82=(a35*a81);
  real_t a83=sin(a0);
  real_t a84=(a83*a56);
  a84=(a36*a84);
  real_t a85=(a37*a84);
  a82=(a82-a85);
  a79=(a79+a82);
  a79=(a79/a5);
  a34=(a34/a5);
  a82=(a34*a58);
  a79=(a79-a82);
  a79=(a79/a5);
  a38=(a38/a5);
  a82=(a38*a58);
  a79=(a79-a82);
  a79=(a39*a79);
  a52=(a52+a79);
  a79=(a1*a52);
  a57=(a31*a57);
  a79=(a79-a57);
  a79=(a41*a79);
  a73=(a73+a79);
  a63=(a63-a73);
  a73=cos(a0);
  a79=(a73*a56);
  a79=(a42*a79);
  a52=(a3*a52);
  a60=(a31*a60);
  a52=(a52-a60);
  a52=(a2*a52);
  a52=(a43*a52);
  a79=(a79+a52);
  a63=(a63-a79);
  a79=sin(a0);
  a52=(a79*a56);
  a52=(a45*a52);
  a84=(a44*a84);
  a60=(a44/a5);
  a58=(a60*a58);
  a57=(a35*a58);
  a84=(a84+a57);
  a84=(a46*a84);
  a52=(a52+a84);
  a63=(a63-a52);
  a52=cos(a0);
  a84=(a52*a56);
  a84=(a47*a84);
  a81=(a44*a81);
  a57=(a37*a58);
  a81=(a81-a57);
  a81=(a36*a81);
  a81=(a48*a81);
  a84=(a84+a81);
  a63=(a63-a84);
  a84=(a49*a12);
  a81=(a44*a12);
  a57=(a18*a58);
  a81=(a81-a57);
  a57=(a18*a81);
  a84=(a84+a57);
  a84=(a17*a84);
  a84=(a51*a84);
  a0=sin(a0);
  a57=(a0*a56);
  a57=(a50*a57);
  a84=(a84-a57);
  a63=(a63+a84);
  a56=(a56*a63);
  a65=(a8*a65);
  a84=(a27*a62);
  a65=(a65-a84);
  a72=(a19*a72);
  a53=(a26*a53);
  a72=(a72+a53);
  a65=(a65+a72);
  a78=(a44*a78);
  a72=(a33*a58);
  a78=(a78-a72);
  a65=(a65+a78);
  a77=(a49*a77);
  a81=(a32*a81);
  a77=(a77+a81);
  a65=(a65+a77);
  a12=(a12*a65);
  a56=(a56+a12);
  if (res[1]!=0) res[1][0]=a56;
  a56=arg[1] ? arg[1][6] : 0;
  a12=(a56*a63);
  a77=arg[1] ? arg[1][7] : 0;
  a81=(a77*a65);
  a12=(a12+a81);
  if (res[1]!=0) res[1][1]=a12;
  a12=arg[1] ? arg[1][10] : 0;
  a81=(a12*a63);
  a78=arg[1] ? arg[1][11] : 0;
  a72=(a78*a65);
  a81=(a81+a72);
  if (res[1]!=0) res[1][2]=a81;
  a81=arg[1] ? arg[1][14] : 0;
  a72=(a81*a63);
  a53=arg[1] ? arg[1][15] : 0;
  a84=(a53*a65);
  a72=(a72+a84);
  if (res[1]!=0) res[1][3]=a72;
  a72=arg[2] ? arg[2][2] : 0;
  a63=(a72*a63);
  a84=arg[2] ? arg[2][3] : 0;
  a65=(a84*a65);
  a63=(a63+a65);
  a75=(a8*a75);
  a62=(a29*a62);
  a75=(a75+a62);
  a75=(a75+a58);
  a63=(a63-a75);
  if (res[1]!=0) res[1][4]=a63;
  a63=(a19*a77);
  a75=(a8*a77);
  a58=(a55*a56);
  a58=(a2*a58);
  a62=(a3*a58);
  a65=(a59*a56);
  a57=(a1*a65);
  a62=(a62+a57);
  a57=(a4*a62);
  a82=(a54*a57);
  a85=(a18*a82);
  a75=(a75-a85);
  a85=(a18*a75);
  a63=(a63+a85);
  a85=(a16*a63);
  real_t a86=(a64*a56);
  a86=(a17*a86);
  real_t a87=(a20*a86);
  a85=(a85-a87);
  a85=(a22*a85);
  a87=(a66*a56);
  a87=(a21*a87);
  a85=(a85-a87);
  a87=(a67*a56);
  a87=(a10*a87);
  real_t a88=(a9*a82);
  a88=(a11*a88);
  a87=(a87+a88);
  a88=(a69*a56);
  a88=(a14*a88);
  real_t a89=(a13*a82);
  a89=(a15*a89);
  a88=(a88-a89);
  a87=(a87+a88);
  a85=(a85-a87);
  a87=(a68*a56);
  a87=(a24*a87);
  a88=(a71*a56);
  a89=(a20*a88);
  a63=(a23*a63);
  a89=(a89+a63);
  a89=(a17*a89);
  a89=(a25*a89);
  a87=(a87+a89);
  a85=(a85-a87);
  a87=(a70*a56);
  a87=(a40*a87);
  a88=(a16*a88);
  a86=(a23*a86);
  a88=(a88-a86);
  a86=(a18*a88);
  a89=(a26*a77);
  a86=(a86+a89);
  a89=(a18*a86);
  a63=(a27*a77);
  a89=(a89+a63);
  a63=(a74*a56);
  real_t a90=(a13*a63);
  a89=(a89-a90);
  a90=(a76*a56);
  a90=(a9*a90);
  a89=(a89+a90);
  a89=(a89/a6);
  a90=(a28*a57);
  a89=(a89-a90);
  a89=(a89/a6);
  a57=(a30*a57);
  a89=(a89-a57);
  a89=(a7*a89);
  a89=(a4*a89);
  a57=(a61*a56);
  a57=(a17*a57);
  a90=(a18*a57);
  real_t a91=(a32*a77);
  a90=(a90+a91);
  a91=(a18*a90);
  real_t a92=(a33*a77);
  a91=(a91+a92);
  a92=(a80*a56);
  real_t a93=(a35*a92);
  real_t a94=(a83*a56);
  a94=(a36*a94);
  real_t a95=(a37*a94);
  a93=(a93-a95);
  a91=(a91+a93);
  a91=(a91/a5);
  a93=(a34*a62);
  a91=(a91-a93);
  a91=(a91/a5);
  a93=(a38*a62);
  a91=(a91-a93);
  a91=(a39*a91);
  a89=(a89+a91);
  a91=(a1*a89);
  a58=(a31*a58);
  a91=(a91-a58);
  a91=(a41*a91);
  a87=(a87+a91);
  a85=(a85-a87);
  a87=(a73*a56);
  a87=(a42*a87);
  a89=(a3*a89);
  a65=(a31*a65);
  a89=(a89-a65);
  a89=(a2*a89);
  a89=(a43*a89);
  a87=(a87+a89);
  a85=(a85-a87);
  a87=(a79*a56);
  a87=(a45*a87);
  a94=(a44*a94);
  a62=(a60*a62);
  a89=(a35*a62);
  a94=(a94+a89);
  a94=(a46*a94);
  a87=(a87+a94);
  a85=(a85-a87);
  a87=(a52*a56);
  a87=(a47*a87);
  a92=(a44*a92);
  a94=(a37*a62);
  a92=(a92-a94);
  a92=(a36*a92);
  a92=(a48*a92);
  a87=(a87+a92);
  a85=(a85-a87);
  a87=(a49*a77);
  a92=(a44*a77);
  a94=(a18*a62);
  a92=(a92-a94);
  a94=(a18*a92);
  a87=(a87+a94);
  a87=(a17*a87);
  a87=(a51*a87);
  a94=(a0*a56);
  a94=(a50*a94);
  a87=(a87-a94);
  a85=(a85+a87);
  a56=(a56*a85);
  a86=(a8*a86);
  a87=(a27*a82);
  a86=(a86-a87);
  a88=(a19*a88);
  a75=(a26*a75);
  a88=(a88+a75);
  a86=(a86+a88);
  a90=(a44*a90);
  a88=(a33*a62);
  a90=(a90-a88);
  a86=(a86+a90);
  a57=(a49*a57);
  a92=(a32*a92);
  a57=(a57+a92);
  a86=(a86+a57);
  a77=(a77*a86);
  a56=(a56+a77);
  if (res[1]!=0) res[1][5]=a56;
  a56=(a12*a85);
  a77=(a78*a86);
  a56=(a56+a77);
  if (res[1]!=0) res[1][6]=a56;
  a56=(a81*a85);
  a77=(a53*a86);
  a56=(a56+a77);
  if (res[1]!=0) res[1][7]=a56;
  a85=(a72*a85);
  a86=(a84*a86);
  a85=(a85+a86);
  a63=(a8*a63);
  a82=(a29*a82);
  a63=(a63+a82);
  a63=(a63+a62);
  a85=(a85-a63);
  if (res[1]!=0) res[1][8]=a85;
  a85=(a19*a78);
  a63=(a8*a78);
  a62=(a55*a12);
  a62=(a2*a62);
  a82=(a3*a62);
  a86=(a59*a12);
  a56=(a1*a86);
  a82=(a82+a56);
  a56=(a4*a82);
  a77=(a54*a56);
  a57=(a18*a77);
  a63=(a63-a57);
  a57=(a18*a63);
  a85=(a85+a57);
  a57=(a16*a85);
  a92=(a64*a12);
  a92=(a17*a92);
  a90=(a20*a92);
  a57=(a57-a90);
  a57=(a22*a57);
  a90=(a66*a12);
  a90=(a21*a90);
  a57=(a57-a90);
  a90=(a67*a12);
  a90=(a10*a90);
  a88=(a9*a77);
  a88=(a11*a88);
  a90=(a90+a88);
  a88=(a69*a12);
  a88=(a14*a88);
  a75=(a13*a77);
  a75=(a15*a75);
  a88=(a88-a75);
  a90=(a90+a88);
  a57=(a57-a90);
  a90=(a68*a12);
  a90=(a24*a90);
  a88=(a71*a12);
  a75=(a20*a88);
  a85=(a23*a85);
  a75=(a75+a85);
  a75=(a17*a75);
  a75=(a25*a75);
  a90=(a90+a75);
  a57=(a57-a90);
  a90=(a70*a12);
  a90=(a40*a90);
  a88=(a16*a88);
  a92=(a23*a92);
  a88=(a88-a92);
  a92=(a18*a88);
  a75=(a26*a78);
  a92=(a92+a75);
  a75=(a18*a92);
  a85=(a27*a78);
  a75=(a75+a85);
  a85=(a74*a12);
  a87=(a13*a85);
  a75=(a75-a87);
  a87=(a76*a12);
  a87=(a9*a87);
  a75=(a75+a87);
  a75=(a75/a6);
  a87=(a28*a56);
  a75=(a75-a87);
  a75=(a75/a6);
  a56=(a30*a56);
  a75=(a75-a56);
  a75=(a7*a75);
  a75=(a4*a75);
  a56=(a61*a12);
  a56=(a17*a56);
  a87=(a18*a56);
  a94=(a32*a78);
  a87=(a87+a94);
  a94=(a18*a87);
  a89=(a33*a78);
  a94=(a94+a89);
  a89=(a80*a12);
  a65=(a35*a89);
  a91=(a83*a12);
  a91=(a36*a91);
  a58=(a37*a91);
  a65=(a65-a58);
  a94=(a94+a65);
  a94=(a94/a5);
  a65=(a34*a82);
  a94=(a94-a65);
  a94=(a94/a5);
  a65=(a38*a82);
  a94=(a94-a65);
  a94=(a39*a94);
  a75=(a75+a94);
  a94=(a1*a75);
  a62=(a31*a62);
  a94=(a94-a62);
  a94=(a41*a94);
  a90=(a90+a94);
  a57=(a57-a90);
  a90=(a73*a12);
  a90=(a42*a90);
  a75=(a3*a75);
  a86=(a31*a86);
  a75=(a75-a86);
  a75=(a2*a75);
  a75=(a43*a75);
  a90=(a90+a75);
  a57=(a57-a90);
  a90=(a79*a12);
  a90=(a45*a90);
  a91=(a44*a91);
  a82=(a60*a82);
  a75=(a35*a82);
  a91=(a91+a75);
  a91=(a46*a91);
  a90=(a90+a91);
  a57=(a57-a90);
  a90=(a52*a12);
  a90=(a47*a90);
  a89=(a44*a89);
  a91=(a37*a82);
  a89=(a89-a91);
  a89=(a36*a89);
  a89=(a48*a89);
  a90=(a90+a89);
  a57=(a57-a90);
  a90=(a49*a78);
  a89=(a44*a78);
  a91=(a18*a82);
  a89=(a89-a91);
  a91=(a18*a89);
  a90=(a90+a91);
  a90=(a17*a90);
  a90=(a51*a90);
  a91=(a0*a12);
  a91=(a50*a91);
  a90=(a90-a91);
  a57=(a57+a90);
  a12=(a12*a57);
  a92=(a8*a92);
  a90=(a27*a77);
  a92=(a92-a90);
  a88=(a19*a88);
  a63=(a26*a63);
  a88=(a88+a63);
  a92=(a92+a88);
  a87=(a44*a87);
  a88=(a33*a82);
  a87=(a87-a88);
  a92=(a92+a87);
  a56=(a49*a56);
  a89=(a32*a89);
  a56=(a56+a89);
  a92=(a92+a56);
  a78=(a78*a92);
  a12=(a12+a78);
  if (res[1]!=0) res[1][9]=a12;
  a12=(a81*a57);
  a78=(a53*a92);
  a12=(a12+a78);
  if (res[1]!=0) res[1][10]=a12;
  a57=(a72*a57);
  a92=(a84*a92);
  a57=(a57+a92);
  a85=(a8*a85);
  a77=(a29*a77);
  a85=(a85+a77);
  a85=(a85+a82);
  a57=(a57-a85);
  if (res[1]!=0) res[1][11]=a57;
  a57=(a19*a53);
  a85=(a8*a53);
  a82=(a55*a81);
  a82=(a2*a82);
  a77=(a3*a82);
  a92=(a59*a81);
  a12=(a1*a92);
  a77=(a77+a12);
  a12=(a4*a77);
  a78=(a54*a12);
  a56=(a18*a78);
  a85=(a85-a56);
  a56=(a18*a85);
  a57=(a57+a56);
  a56=(a16*a57);
  a89=(a64*a81);
  a89=(a17*a89);
  a87=(a20*a89);
  a56=(a56-a87);
  a56=(a22*a56);
  a87=(a66*a81);
  a87=(a21*a87);
  a56=(a56-a87);
  a87=(a67*a81);
  a87=(a10*a87);
  a88=(a9*a78);
  a88=(a11*a88);
  a87=(a87+a88);
  a88=(a69*a81);
  a88=(a14*a88);
  a63=(a13*a78);
  a63=(a15*a63);
  a88=(a88-a63);
  a87=(a87+a88);
  a56=(a56-a87);
  a87=(a68*a81);
  a87=(a24*a87);
  a88=(a71*a81);
  a63=(a20*a88);
  a57=(a23*a57);
  a63=(a63+a57);
  a63=(a17*a63);
  a63=(a25*a63);
  a87=(a87+a63);
  a56=(a56-a87);
  a87=(a70*a81);
  a87=(a40*a87);
  a88=(a16*a88);
  a89=(a23*a89);
  a88=(a88-a89);
  a89=(a18*a88);
  a63=(a26*a53);
  a89=(a89+a63);
  a63=(a18*a89);
  a57=(a27*a53);
  a63=(a63+a57);
  a57=(a74*a81);
  a90=(a13*a57);
  a63=(a63-a90);
  a90=(a76*a81);
  a90=(a9*a90);
  a63=(a63+a90);
  a63=(a63/a6);
  a90=(a28*a12);
  a63=(a63-a90);
  a63=(a63/a6);
  a12=(a30*a12);
  a63=(a63-a12);
  a63=(a7*a63);
  a63=(a4*a63);
  a12=(a61*a81);
  a12=(a17*a12);
  a90=(a18*a12);
  a91=(a32*a53);
  a90=(a90+a91);
  a91=(a18*a90);
  a75=(a33*a53);
  a91=(a91+a75);
  a75=(a80*a81);
  a86=(a35*a75);
  a94=(a83*a81);
  a94=(a36*a94);
  a62=(a37*a94);
  a86=(a86-a62);
  a91=(a91+a86);
  a91=(a91/a5);
  a86=(a34*a77);
  a91=(a91-a86);
  a91=(a91/a5);
  a86=(a38*a77);
  a91=(a91-a86);
  a91=(a39*a91);
  a63=(a63+a91);
  a91=(a1*a63);
  a82=(a31*a82);
  a91=(a91-a82);
  a91=(a41*a91);
  a87=(a87+a91);
  a56=(a56-a87);
  a87=(a73*a81);
  a87=(a42*a87);
  a63=(a3*a63);
  a92=(a31*a92);
  a63=(a63-a92);
  a63=(a2*a63);
  a63=(a43*a63);
  a87=(a87+a63);
  a56=(a56-a87);
  a87=(a79*a81);
  a87=(a45*a87);
  a94=(a44*a94);
  a77=(a60*a77);
  a63=(a35*a77);
  a94=(a94+a63);
  a94=(a46*a94);
  a87=(a87+a94);
  a56=(a56-a87);
  a87=(a52*a81);
  a87=(a47*a87);
  a75=(a44*a75);
  a94=(a37*a77);
  a75=(a75-a94);
  a75=(a36*a75);
  a75=(a48*a75);
  a87=(a87+a75);
  a56=(a56-a87);
  a87=(a49*a53);
  a75=(a44*a53);
  a94=(a18*a77);
  a75=(a75-a94);
  a94=(a18*a75);
  a87=(a87+a94);
  a87=(a17*a87);
  a87=(a51*a87);
  a94=(a0*a81);
  a94=(a50*a94);
  a87=(a87-a94);
  a56=(a56+a87);
  a81=(a81*a56);
  a89=(a8*a89);
  a87=(a27*a78);
  a89=(a89-a87);
  a88=(a19*a88);
  a85=(a26*a85);
  a88=(a88+a85);
  a89=(a89+a88);
  a90=(a44*a90);
  a88=(a33*a77);
  a90=(a90-a88);
  a89=(a89+a90);
  a12=(a49*a12);
  a75=(a32*a75);
  a12=(a12+a75);
  a89=(a89+a12);
  a53=(a53*a89);
  a81=(a81+a53);
  if (res[1]!=0) res[1][12]=a81;
  a56=(a72*a56);
  a89=(a84*a89);
  a56=(a56+a89);
  a57=(a8*a57);
  a78=(a29*a78);
  a57=(a57+a78);
  a57=(a57+a77);
  a56=(a56-a57);
  if (res[1]!=0) res[1][13]=a56;
  a56=(a19*a84);
  a57=(a8*a84);
  a55=(a55*a72);
  a55=(a2*a55);
  a77=(a3*a55);
  a59=(a59*a72);
  a78=(a1*a59);
  a77=(a77+a78);
  a78=(a4*a77);
  a54=(a54*a78);
  a89=(a18*a54);
  a57=(a57-a89);
  a89=(a18*a57);
  a56=(a56+a89);
  a89=(a16*a56);
  a64=(a64*a72);
  a64=(a17*a64);
  a81=(a20*a64);
  a89=(a89-a81);
  a22=(a22*a89);
  a66=(a66*a72);
  a21=(a21*a66);
  a22=(a22-a21);
  a67=(a67*a72);
  a10=(a10*a67);
  a67=(a9*a54);
  a11=(a11*a67);
  a10=(a10+a11);
  a69=(a69*a72);
  a14=(a14*a69);
  a69=(a13*a54);
  a69=(a8-a69);
  a15=(a15*a69);
  a14=(a14+a15);
  a10=(a10+a14);
  a22=(a22-a10);
  a68=(a68*a72);
  a24=(a24*a68);
  a71=(a71*a72);
  a20=(a20*a71);
  a56=(a23*a56);
  a20=(a20+a56);
  a20=(a17*a20);
  a25=(a25*a20);
  a24=(a24+a25);
  a22=(a22-a24);
  a70=(a70*a72);
  a40=(a40*a70);
  a16=(a16*a71);
  a23=(a23*a64);
  a16=(a16-a23);
  a23=(a18*a16);
  a64=(a26*a84);
  a23=(a23+a64);
  a64=(a18*a23);
  a71=(a27*a84);
  a64=(a64+a71);
  a74=(a74*a72);
  a13=(a13*a74);
  a13=(a29-a13);
  a64=(a64+a13);
  a76=(a76*a72);
  a9=(a9*a76);
  a64=(a64+a9);
  a64=(a64/a6);
  a28=(a28*a78);
  a64=(a64-a28);
  a64=(a64/a6);
  a30=(a30*a78);
  a64=(a64-a30);
  a7=(a7*a64);
  a4=(a4*a7);
  a61=(a61*a72);
  a61=(a17*a61);
  a7=(a18*a61);
  a64=(a32*a84);
  a7=(a7+a64);
  a64=(a18*a7);
  a30=(a33*a84);
  a64=(a64+a30);
  a80=(a80*a72);
  a30=(a35*a80);
  a83=(a83*a72);
  a83=(a36*a83);
  a78=(a37*a83);
  a30=(a30-a78);
  a64=(a64+a30);
  a30=1.;
  a64=(a64+a30);
  a64=(a64/a5);
  a34=(a34*a77);
  a64=(a64-a34);
  a64=(a64/a5);
  a38=(a38*a77);
  a64=(a64-a38);
  a39=(a39*a64);
  a4=(a4+a39);
  a1=(a1*a4);
  a55=(a31*a55);
  a1=(a1-a55);
  a41=(a41*a1);
  a40=(a40+a41);
  a22=(a22-a40);
  a73=(a73*a72);
  a42=(a42*a73);
  a3=(a3*a4);
  a31=(a31*a59);
  a3=(a3-a31);
  a2=(a2*a3);
  a43=(a43*a2);
  a42=(a42+a43);
  a22=(a22-a42);
  a79=(a79*a72);
  a45=(a45*a79);
  a83=(a44*a83);
  a60=(a60*a77);
  a35=(a35*a60);
  a83=(a83+a35);
  a46=(a46*a83);
  a45=(a45+a46);
  a22=(a22-a45);
  a52=(a52*a72);
  a47=(a47*a52);
  a80=(a44*a80);
  a37=(a37*a60);
  a80=(a80-a37);
  a36=(a36*a80);
  a48=(a48*a36);
  a47=(a47+a48);
  a22=(a22-a47);
  a47=(a49*a84);
  a48=(a44*a84);
  a36=(a18*a60);
  a48=(a48-a36);
  a18=(a18*a48);
  a47=(a47+a18);
  a17=(a17*a47);
  a51=(a51*a17);
  a0=(a0*a72);
  a50=(a50*a0);
  a51=(a51-a50);
  a22=(a22+a51);
  a72=(a72*a22);
  a23=(a8*a23);
  a27=(a27*a54);
  a23=(a23-a27);
  a19=(a19*a16);
  a26=(a26*a57);
  a19=(a19+a26);
  a23=(a23+a19);
  a44=(a44*a7);
  a33=(a33*a60);
  a44=(a44-a33);
  a23=(a23+a44);
  a49=(a49*a61);
  a32=(a32*a48);
  a49=(a49+a32);
  a23=(a23+a49);
  a84=(a84*a23);
  a72=(a72+a84);
  a8=(a8*a74);
  a29=(a29*a54);
  a8=(a8+a29);
  a8=(a8+a60);
  a72=(a72-a8);
  if (res[1]!=0) res[1][14]=a72;
  return 0;
}

void adjFun_incref(void) {
}

void adjFun_decref(void) {
}

int adjFun_n_in(void) { return 5;}

int adjFun_n_out(void) { return 2;}

const char* adjFun_name_in(int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    case 4: return "i4";
    default: return 0;
  }
}

const char* adjFun_name_out(int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    default: return 0;
  }
}

const int* adjFun_sparsity_in(int i) {
  switch (i) {
    case 0: return s0;
    case 1: return s1;
    case 2: return s0;
    case 3: return s0;
    case 4: return s2;
    default: return 0;
  }
}

const int* adjFun_sparsity_out(int i) {
  switch (i) {
    case 0: return s3;
    case 1: return s4;
    default: return 0;
  }
}

int adjFun_work(int *sz_arg, int* sz_res, int *sz_iw, int *sz_w) {
  if (sz_arg) *sz_arg = 5;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 96;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
