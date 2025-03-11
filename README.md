The bot searches all avalibable moves using depth first search.
It performs the moves to a certain depth (this depth is changable).
Then after it uses a evaluation algorithm (the number of points +- the favoribility of the square its on), to yield if those series of moves result in the best possible position for the bot.
Then it returns the best posssible move.

If I would change this, I would try to add AI to the evaluation function to make it more concrete, as right now the algorithm is based on a general rule of thumb.
I would also rewrite this in C++ as python runs too slowly.
i would also implement some sort of pruning to the tree, elimenating any move that is obviously wrong (to prevent wasting time).
