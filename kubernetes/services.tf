resource "kubernetes_service" "app" {
  metadata {
    name = var.app
  }
  spec {
    selector = {
      app = kubernetes_deployment.app.metadata.0.labels.app
    }
    port {
      port        = 8555
      target_port = 8555
    }
    type = "NodePort"
  }
} 