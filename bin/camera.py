from picamera import PiCamera
from time import sleep

camera = PiCamera()
camera.resolution = (1280,720)
#camera.preview_window = (640,480)
#camera.framerate = 60
camera.start_preview(fullscreen=False,window=(100,100,640,480))
sleep(60)
camera.stop_preview()
