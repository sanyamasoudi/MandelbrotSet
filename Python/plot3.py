from PIL import Image, ImageDraw
from mandelbrot import mandelbrot, MAX_ITER

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
        if m==2:
            hue = int(255 * m / MAX_ITER)+m
            saturation = 255
        elif m==3:
            hue = int(255 * m / MAX_ITER)+2*m
            saturation = 255
        elif m==4:
            hue = int(255 * m / MAX_ITER)+3*m
            saturation = 255
        elif m==5:
            hue = int(255 * m / MAX_ITER)+4*m
            saturation = 255
        elif m==6:
            hue = int(255 * m / MAX_ITER)+5*m
            saturation = 255
        elif m==7:
            hue = int(255 * m / MAX_ITER)+6*m
            saturation = 25
        elif m==8:
            hue = int(255 * m / MAX_ITER)+7*m
            saturation = 255
        elif m==9:
            hue = int(255 * m / MAX_ITER)+8*m
            saturation = 255
        elif m==10:
            hue = int(255 * m / MAX_ITER)+9*m
            saturation = 255
        else:
            hue = int(255 * m / MAX_ITER)
            saturation = 255
        value = 255 if m < MAX_ITER else 0
        # Plot the point
        draw.point([x, y], (hue, saturation, value))

im.convert('RGB').save('output15.png', 'PNG')

