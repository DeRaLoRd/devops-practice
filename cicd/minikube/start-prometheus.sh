#!/bin/bash

helm install prometheus prom-repo/kube-prometheus-stack \
	--set prometheus.service.type=NodePort \
	--set grafana.service.type=NodePort \
	--set grafana.adminPassword=admin 

minikube ip

echo "Use IP above and 'kubectl get svc' for ports to access web-interface"
