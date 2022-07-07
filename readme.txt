-- Introduction --
  Push_swap is an introduction to sorting algorithm, but the sorting operation in limited.
  In order to sort all member in ascending order, you are provided with two arrays; stack A and B.
  When the program started, it will create stack A with random numbers that never duplicate and within INT range.
  The swap operations is limited to the following commands
  1) swap [sa, sp, sr] = swap the array[0] to the array[1]
  2) push [pa, pb] = push array[0] 
  3) rotate [ra, rb, rr] = shift array[1] to array[0], array[0] will be array[last]
  4) reverse rotate [rra, rrb, rrr] = shift array[0] to array[1], opposite to rotate.
