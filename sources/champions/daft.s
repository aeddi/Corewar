.name "DAFT CHAMP CHAMP"
.comment "I'M DAFT AND I'LL KILL YOU"

# HARD CHAMP
# st r1, 11       # copy r1 at live arg
# ld 6, r1        # copy live arg to r1
# live %0         # live
#  = 03 70 01 00 0b 02 d0 00 07 01 01 00 00 00 00
#  = 57671936  + 184733696 + 117506304 + 0

# LOAD HARD CHAMP:
ld %57671936, r4
ld %184733696, r3
ld %100729088, r2


# HARD COPY CHAMP
st r4, 15
st r3, 14
st r2, 13
live %0
live %0
live %0
add r10, r10, r10
fork %-20
