#include<stdio.h>
#include<stdlib.h>
#include"defs.h"
#include"utils.h"
#include"mandelbrotset.h"

int main(int argc, char** argv)
{
    Config cfg; memset(&cfg, 0, sizeof(Config));
    ImageState state; memset(&state, 0, sizeof(ImageState));
    ProcessArgs(argc, argv, &cfg, &state);
    UpdateImageData(&state);
    WriteBitmapFile(state.image_count++, & state.bmFileData);

    for(int i=0;i<cfg.CmdCount; i++)
    {
        switch (cfg.Commands[i].cmd)
        {
            case ct_Center:
                ChangeCenter(&state, cfg.Commands[i].cx, cfg.Commands[i].cy, cfg.Commands[i].steps);
                break;
            
            case ct_Zoom:
                ChangeZoom(&state,cfg.Commands[i].zoom, cfg.Commands[i].xpos,cfg.Commands[i].ypos, cfg.Commands[i].steps);
                break;

            case ct_Rotate:
                ChangeRotation(&state, cfg.Commands[i].angle, cfg.Commands[i].steps);
                break;

            case ct_Hold:
                Hold(&state, cfg.Commands[i].steps);
                break;
            case ct_ZoomOutCenter:
                ChangeZoomOutCenter(&state,cfg.Commands[i].zoom, cfg.Commands[i].xpos,cfg.Commands[i].ypos, cfg.Commands[i].steps);
                break;

        }
    }
    return 0;
}