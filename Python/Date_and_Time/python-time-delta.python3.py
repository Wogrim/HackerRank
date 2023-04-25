"""total number of seconds between 2 dates & times"""

import datetime

def time_delta(t1, t2):
    #parse specifically-formatted input string as datetime
    dt1 = datetime.datetime.strptime(t1,"%a %d %b %Y %H:%M:%S %z")
    dt2 = datetime.datetime.strptime(t2,"%a %d %b %Y %H:%M:%S %z")
    #subtracting datetime from datetime gives a timedelta
    td = abs(dt1 - dt2)
    return str(int(td.total_seconds()))
