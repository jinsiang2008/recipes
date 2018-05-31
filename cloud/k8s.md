# Kubernetes notes
## Libraries
+ [Jaeger](https://github.com/jaegertracing/jaeger): tracing
+ [kops](https://github.com/kubernetes/kops): k8s install/upgrade/management
## [kubectl tips and tricks](https://discuss.kubernetes.io/t/kubectl-tips-and-tricks/192/7)
+ `kubectl alpha diff --help`: analyzes two kubernetes resources and prints the lines that are different.
+ `kubectl get pods --watch`: watch pod status
+ `kubectl top node`, `kubectl top pod` to see node/pod cpu/memory usage
