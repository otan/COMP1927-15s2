#!/usr/bin/python

import random

# test graph sizes 5-30
for cols in xrange(5, 31, 5):
  for rows in xrange(5, 31, 5):
    # test 5 ranges
    for N in xrange(1, 3):
      with open("%d-%d-%d.test" % (cols, rows, N), "w") as f:
        f.write("%d %d\n" % (cols, rows))
        for y in xrange(cols):
          for x in xrange(rows):
            f.write("%d " % (random.randint(0, 1)))
          f.write("\n")
