variable "cluster" {
  default = "mmo-workshops"
}
variable "app" {
  type        = string
  description = "MMO Framework"
  default     = "mmo-framework"
}
variable "docker-image"  {
  type        = string
  description = "name of the docker image to deploy"
  default     = "localhost:5000/game_node:latest"
}