# From: http://mp.weixin.qq.com/s/wt4zxkMXimG9VdgBK6B70A
import resource

""" Get current proces memory usage
    ru_maxrss varies from platforms (Byte in OSX and KB in Linux)
    ref: https://www.gnu.org/software/libc/manual/html_node/Resource-Usage.html
    Use resource.RUSAGE_SELF to present current process,
        resource.RUSAGE_CHILDREN to present child process,
        resource.RUSAGE_BOTH to present total
"""
mem_init = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
l = []
for i in range(500000):
    l.append(object())
mem_final = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
del l
print('Class: {}:\n'.format(getattr(cls, '__name__')))
print('Initial RAM usage: {:14,}'.format(mem_init))
print('  Final RAM usage: {:14,}'.format(mem_final))
