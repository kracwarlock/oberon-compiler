MODULE S2searchwords;

(* Count occurrences of words in a text: binary search tree version. *)

(* This program expects a sequence of lower-case words on the standard
   input.  It outputs on standard output a table of words and their
   frequency of occurrence in the input.

   An ordinary text file can be prepared for input to this program
   with the unix commands "tr -cs A-Za-z '\n' | tr A-Z a-z".  The
   program itself performs the same function as "sort | uniq -c". *)

IMPORT In, Out;

TYPE Tree = POINTER TO Node;
  Node = RECORD
      word: ARRAY 20 OF CHAR; 
      count: INTEGER; 
      left, right: Tree;
    END;

PROCEDURE IncWord(VAR s: ARRAY OF CHAR; VAR p: Tree) : INTEGER;
  VAR q: Tree;
BEGIN
  IF (p = NIL) THEN
    (*NEW(q);
    COPY(s, q.word);*)           (*check here*)
    q.count := 1; 
    q.left := NIL;
    q.right := NIL;
    p := q;
  ELSIF p.word = s THEN
    p.count := p.count + 1;
  ELSIF s < p.word THEN
    IncWord(s, p.left);
  ELSE
    IncWord(s, p.right);
  END;
END IncWord;

(*
Recursive version of |Output|:

PROCEDURE Output(p: Tree);
BEGIN
  IF p # NIL THEN
    Output(p.left);
    Out.Int(p.count, 7); Out.Char(' '); Out.String(p.word); Out.Ln;
    Output(p.right);
  END
END Output;
*)

PROCEDURE Output(p: Tree);
  VAR sp: INTEGER;
    stack: ARRAY 1000 OF Tree;
BEGIN
  sp := 0;
END Output; 

PROCEDURE Main;
  VAR word: ARRAY 20 OF CHAR;
    root: Tree;
BEGIN
  root := NIL;
  Output(root);
END Main;

BEGIN
  Main;
END S2searchwords.
