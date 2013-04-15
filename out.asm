main:
li	$t0,0
sw	$t0,12($sp)

L0:
li	$t0,1
sw	$t0,16($sp)
lw	$t0,16($sp)
beqz	$t0,L1
li	$t0,3
sw	$t0,20($sp)
b	L0

L1:
li	$v0,10
syscall
