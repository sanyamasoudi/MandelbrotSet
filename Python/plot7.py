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
        c = complex(RE_START + (x / WIDTH) * (RE_END - RE_START),
                    IM_START + (y / HEIGHT) * (IM_END - IM_START))
        # Compute the number of iterations
        m = mandelbrot(c)
        # The color depends on the number of iterations
        if 1<=m<10:
            hue = int(255 * m / MAX_ITER)
            saturation = 255
        elif 10<=m<100:
            hue = int(355 * m / MAX_ITER)+2*m
            saturation = 255
        elif 100<=m<1000:
            hue = int(455 * m / MAX_ITER)+3*m
            saturation = 255
        elif 1001<=m<10000:
            hue = int(555 * m / MAX_ITER)+4*m
            saturation = 255
        elif 10001<=m<100000:
            hue = int(655 * m / MAX_ITER)+4*m
            saturation = 255
        elif 100001<=m<1000000:
            hue = int(755 * m / MAX_ITER)+4*m
            saturation = 255
        elif 1000001<=m<10000000:
            hue = int(855 * m / MAX_ITER)+4*m
            saturation = 255
        elif 10000001<=m<100000000:
            hue = int(955 * m / MAX_ITER)+4*m
            saturation = 255
        else:
            hue = int( m / MAX_ITER)+m
            saturation = 255
        value = 255 if m < MAX_ITER else 0
        # Plot the point
        draw.point([x, y], (hue, saturation, value))

im.convert('RGB').save('output21.png', 'PNG')


