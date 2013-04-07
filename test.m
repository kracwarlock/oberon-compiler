MODULE L0Total;

(* Read a file of integers from standard 
   input and print the total *)

IMPORT In, Out;

CONST MAX = 10;

TYPE
  y = INTEGER;
  z = y;
  m = BOOLEAN;
  N = INTEGER;
  l = ARRAY OF INTEGER;
  rc = RECORD a, b, c: POINTER TO ARRAY OF INTEGER; d: ARRAY OF INTEGER; END;
  rc1 = RECORD a, b, c: POINTER TO ARRAY OF INTEGER; d: ARRAY OF INTEGER; END;
  pi = POINTER TO ARRAY OF INTEGER;
  f = SET;
  fn = PROCEDURE ( a, b: INTEGER; c, d: POINTER TO ARRAY OF INTEGER ) : rc;

VAR 
  o1,o2 : y;
  ol:INTEGER;
  o3 : m;
  o9,o8,o11:f;
  o4 : m;
  o5 : rc;
  o90 : rc1;
  o12 : pi;
  o6 : CHAR;
  o7 : REAL;

BEGIN
  (* Read in the numbers *)
  o5 := o90;
  o8 := {1,2,3,4};
  o1 := ol;
  o3 := o1 IS m;
  o5.a := TRUE;
  o9 := o8 + o1;
  o1 := 10;
  o7 := 20.3;
  o7 := o7+o6;
  o6 := o1+o5.e;
  o5.a := o12;
  o2 := o3 = 10;
  o2 := o3 = TRUE;
  o2 := o4 # 20;

END L0Total.