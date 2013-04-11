MODULE L0Total;

(* Read a file of integers from standard 
   input and print the total *)

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
  o9,o8,o11:f;
  o4 : m;
  o5 : rc;
  o90 : rc1;
  o12 : pi;
  mp : pli;
  plm : m;
  o6 : CHAR;
  o7 : REAL;

BEGIN
  (* Read in the numbers *)
  o5 := o90;
  o8 := {1,2,3,4};
  o1 := ol;
  mp[ol] := 10;
  IF plm = TRUE THEN
   o3 := o1 IS m; 
  END;
  WHILE plm # TRUE DO
    o1 := o1 + 10;
  END;
  ol := mk + o1;
  REPEAT
    o1 := o1 + 10;
  UNTIL plm # TRUE;
  o1 := 10;
  o7 := 20.3;
  o5.a := o12;
  o2 := o3 = TRUE;
  o2 := o3 = TRUE;
  o2 := o4 # FALSE;

END L0Total.