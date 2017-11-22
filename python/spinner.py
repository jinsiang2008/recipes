import time

while True:
    for ch in "-\|/":
        # "\r" carriage to print in place
        # Be aware not to use newline in the end
        # end='' only works in py3
        print ('\r {}'.format(ch), end='')
        time.sleep(0.15)
