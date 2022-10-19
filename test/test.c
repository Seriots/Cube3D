/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:48:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/19 20:30:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <ao/ao.h>
#include <pthread.h>
#include <mpg123.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../z_bonus/include/libs/ft.h"*/


//#define BITS 8
//
//int run_sound(char *file)
//{
//    mpg123_handle *mh;
//    unsigned char *buffer;
//    size_t buffer_size;
//    size_t done;
//    int err;
//
//    int driver;
//    ao_device *dev;
//
//    ao_sample_format format;
//    int channels, encoding;
//    long rate;
//
//    /* initializations */
//    ao_initialize();
//    driver = ao_default_driver_id();
//    mpg123_init();
//    mh = mpg123_new(NULL, &err);
//    buffer_size = mpg123_outblock(mh);
//    buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));
//
//    /* open the file and get the decoding format */
//    mpg123_open(mh, file);
//    mpg123_getformat(mh, &rate, &channels, &encoding);
//
//    /* set the output format and open the output device */
//    format.bits = mpg123_encsize(encoding) * BITS;
//    format.rate = rate;
//    format.channels = channels;
//    format.byte_format = AO_FMT_NATIVE;
//    format.matrix = NULL;
//    dev = ao_open_live(driver, &format, NULL);
//
//    /* decode and play */
//    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
//        ao_play(dev, (char *)buffer, done);
//
//    /* clean up */
//    free(buffer);
//    ao_close(dev);
//    mpg123_close(mh);
//    mpg123_delete(mh);
//    mpg123_exit();
//    ao_shutdown();
//
//    return 0;
//}
//
//int set_volume(int volume)
//{
//    char    cmd[100];
//    char    vol[24];
//
//    ft_strlcpy(cmd, "amixer set -qD pulse Master ", 100);
//    ft_strlcat(cmd, ft_itoa_noalloc(vol, volume), 100);
//    ft_strlcat(cmd, "%", 100);
//    system(cmd);
//    return (0);
//}
//
//pid_t play_sound(char *file, int volume, int wait)
//{
//    pid_t   pid;
//
//    pid = fork();
//    if (pid == -1)
//        return (1);
//    else if (pid == 0)
//    {
//        set_volume(volume);
//        run_sound(file);
//        exit(0);
//    }
//    if (wait)
//        waitpid(pid, NULL, 0);
//    return (pid);
//}
//
//int main(int argc, char *argv[])
//{
//    pid_t       pid;
//
//    if (argc < 2)
//        exit(0);
//    pid = play_sound(argv[1], 40, 0);
//    sleep (5);
//    system("amixer -qD pulse sset Master mute");
//    sleep (5);
//    system("amixer -qD pulse sset Master unmute");
//    waitpid(pid, NULL, 0);
//}*/
//

#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
   int continuer = 1;
   SDL_Init(SDL_INIT_VIDEO);
   SDL_Surface *ecran = NULL;
   ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   SDL_Event event;
   SDL_WM_SetCaption("SDL_Mixer", NULL);
   SDL_Flip(ecran);
   while(continuer)
   {
      SDL_WaitEvent(&amp;event);
      switch(event.type)
      {
         case SDL_QUIT:
            continuer = 0;
            break;
      }
   }
   SDL_Quit();
   return EXIT_SUCCESS;
}
