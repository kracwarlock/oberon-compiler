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
  o8,o9,o11,dif,ins,sym,as :f;
  o4 : m;
  o5 : rc;
  o90 : rc1;
  o12 : pi;
  mp : pli;
  plm : m;
  o6 : CHAR;
  o7 : REAL;
  root: y;

PROCEDURE Main22(ro : y ; olp : INTEGER) : INTEGER ;
VAR root : y;
BEGIN
      ro := 10;
      olp := 1;
      ro := ro + olp;
      root := 10 + ro;
END Main22;

BEGIN
  (* Read in the numbers *)
  ol := 1;
  o1 := ol;
  o5 := o90;
  o8 := {1,2,5,3,4,20};
  as := o8;
  o9 := {1,2,5,4,10,ol};
  o11 := o8 + o9;
  ins := o8 * o9;
  dif := o8 - o9;
  sym := as / o9;
  plm := ol IN sym;
  mp[ol] := 10 + 20*203 + 384 - 303;
  IF plm = TRUE THEN
    IF plm = TRUE THEN
      o3 := o1 IS m; 
    END;
    IF plm # TRUE THEN
      o1 := mk +ol; 
    END;
  END;
  WHILE plm # TRUE DO
    IF plm = TRUE THEN
      o3 := o1 IS m; 
    END;
    o1 := o1 + 10;
  END;
  ol := mk + o1;
  REPEAT
    o1 := o1 + 10;
  UNTIL plm # TRUE;
  o1 := 10;
  o7 := 20.3;
  CASE o1 + o7 OF
    ol : o7 := 312.45;
    & o1 + o1 : o7 := 32.45;
  ELSE
    o7 := 23.3;
  END;
  o5.a := o12;
  ol := Main22(ol+o1,o1+ol);
  o2 := o3 = TRUE;
  o2 := o3 = TRUE;
  o2 := o4 # FALSE;

END L0Total.