MODULE L0Total;

(* Read a file of integers from standard 
   input and print the total *)

(* (* Nested comment 
	implementation in Oberon  *) *)

IMPORT In, Out;

CONST MAX = 10;

TYPE
  a: INTEGER;
  b: CHAR;
  c: BOOLEAN;
  d: REAL;
  e: LONGREAL;

  a := 10;
  b := 01X;
  b := 0AX;
  c := TRUE;
  d := 123.232;
  e := 10001.133311213143;
  
  z := y;
  y := 123.234 + 123.4224;
  y := 123 + 1313;
  y := TRUE;
  y := FALSE;
  y := "String";
  y := A;
  b := 0fX;
  b := 0ffX;
  y := ABS(x);
  y := ODD(x);
  y := LEN(x);
  y := LSL(x,n);
  y := ASR(x,n);
  y := ROR(x,n);
  y := FLOOR(x);
  y := FLT(x);
  y := ORD(x);
  y := CHR(x);
  y := LONG(x);
  y := SHORT(x);
  y := INC(v);
  y := INC(v,n);
  y := DEC(v);
  y := DEC(v,n);
  y := INCL(v,x);
  y := EXCL(v,x);
  y := COPY(x,v);
  y := NEW(v);
  y := ASSERT(b);
  y := ASSERT(b,n);
  y := PACK(x,y);
  y := UNPK(x,y);
  rc := RECORD a, b, c: INTEGER; d: POINTER TO ARRAY OF INTEGER; END;
  rc1 := RECORD a, b, c: INTEGER; d: POINTER TO ARRAY OF INTEGER; END;
  rc2 := RECORD name, firstname: ARRAY 32 OF CHAR; age: INTEGER; salary: REAL; check : rc1; END
  fn := PROCEDURE ( a, b: INTEGER; c, d: POINTER TO ARRAY OF INTEGER ) : rc;

VAR s0: SET;
s0 := {8,10..12,15};

BEGIN
  (* Read in the numbers *)
  N := 0;
  In.Int(x);
  WHILE In.Done DO
    pints[N] := x;
    N := N + 1;
    In.Int(x)
  END;

  (* Compute the total *)
  k := 0; total := 0;
  WHILE k < N DO
    total := total + pints[k];
    k := k + 1;
  END;

  (* Print the total *)
  Out.Int(total, 0); Out.Ln
END L0Total.
