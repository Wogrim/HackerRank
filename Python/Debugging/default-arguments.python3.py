"""mutable default arguments don't get created each time"""

def print_from_stream(n, stream=EvenStream()):
    # you can run the constructor to re-initialize
    stream.__init__()
    for _ in range(n):
        print(stream.get_next())


# OR
def print_from_stream(n, stream=None):
    if stream==None:
        stream = EvenStream()
    for _ in range(n):
        print(stream.get_next())
