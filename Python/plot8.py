from PIL import Image, ImageDraw
from mandelbrot import mandelbrot, MAX_ITER
from math import log

# Image size (pixels)
WIDTH = 2000
HEIGHT = 1300

# Plot window
RE_START = -2.5
RE_END = 1.5
IM_START = -1.5
IM_END = 1.5

im = Image.new('HSV', (WIDTH, HEIGHT), (0, 0, 0))
draw = ImageDraw.Draw(im)

for x in range(0, WIDTH):
    for y in range(0, HEIGHT):
        # Convert pixel coordinate to complex number
        c = complex((RE_START + (x / WIDTH) * (RE_END - RE_START)),
                    (IM_START + (y / HEIGHT) * (IM_END - IM_START)))
        # Compute the number of iterations
        m = mandelbrot(c)
        value = 255 if m < MAX_ITER else 0
        # The color depends on the number of iterations
        if m==2:
            draw.point([x, y], (130, 255,value ))
        elif m==1:
            draw.point([x, y], (233, 255, value))
       
        elif m==3:
            draw.point([x, y], (97, 255, value))
        elif m==4:
            draw.point([x, y], (28, 255, value))
        elif m==5 or m==6 or m==7:
            draw.point([x, y], (197, 255, value))
        elif m==7 or m==8 or m==9:
            draw.point([x, y], (217, 255, value))
        else:
            draw.point([x, y], (int((255 * m / MAX_ITER)), 255, 255))
        
        # Plot the point
        

im.convert('RGB').save('output24.png', 'PNG')

