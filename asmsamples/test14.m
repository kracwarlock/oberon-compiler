MODULE L0Total;

IMPORT In, Out;

TYPE
  y = INTEGER;
  z = y;
  m = BOOLEAN;
  N = INTEGER;
  l = ARRAY OF INTEGER;
  rc = RECORD a, b, c: POINTER TO ARRAY OF INTEGER; d: ARRAY OF INTEGER; END;
  rc1 = RECORD a, b, c: POINTER TO ARRAY OF INTEGER; d: ARRAY OF INTEGER; END;
  pi = POINTER TO ARRAY OF INTEGER;
  pli = ARRAY OF INTEGER;
  f = SET;
  fn = PROCEDURE ( a, b: INTEGER; c, d: POINTER TO ARRAY OF INTEGER ) : rc;

VAR 
  o1 : y;
  o2: m;
  ol,mk :INTEGER;
  o3 : m;
  o8,o9,o11 :f;
  o4 : m;
  o5 : rc;
  o90 : rc1;
  o12 : pi;
  mp : pli;
  plm : m;
  o6 : CHAR;
  o7 : REAL;
  root: y;

BEGIN
  (* Read in the numbers *)
  ol := 1;
  o1 := 0;
  o1 := 100;
  o8 := {1,2,3,4};
  o9 := {4,83,333,1};
  o11 := o8 * o9;
  IF o1 IN o11 THEN
      ol := 10;
  ELSE
      ol := 30;
  END;
END L0Total.