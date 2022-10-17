/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_play_sound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:37:45 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 21:20:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <ao/ao.h>
#include <mpg123.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "c3d_struct.h"

#include "ft.h"

#define BITS 8

int	free_sound(t_sound *sound)
{
    free(sound->buffer);
    ao_close(sound->dev);
    mpg123_close(sound->mh);
    mpg123_delete(sound->mh);
    mpg123_exit();
    ao_shutdown();
	return (0);
}

int	init_sound(t_sound *sound, char *file)
{
	ao_initialize();
    sound->driver = ao_default_driver_id();
    sound->err = mpg123_init();
    if (sound->err != MPG123_OK || sound->driver < 0)
		return (ao_shutdown(), 1);
	sound->mh = mpg123_new(NULL, &sound->err);
	if (!sound->mh)
		return (mpg123_exit(), ao_shutdown(), 1);
    sound->buffer_size = mpg123_outblock(sound->mh);
    sound->buffer = (unsigned char*) malloc(sound->buffer_size
		* sizeof(unsigned char));
    sound->err = mpg123_open(sound->mh, file);
    if (sound->err != MPG123_OK)
		return (free(sound->buffer), mpg123_close(sound->mh),
			mpg123_delete(sound->mh), mpg123_exit(), ao_shutdown(), 1);
	sound->err = mpg123_getformat(sound->mh, &sound->rate,
		&sound->channels, &sound->encoding);
    if (sound->err != MPG123_OK)
		return (free(sound->buffer), mpg123_close(sound->mh),
			mpg123_delete(sound->mh), mpg123_exit(), ao_shutdown(), 1);
	return (0);
}

int	run_sound(char *file)
{
	t_sound	sound;
	int		err;

	err = init_sound(&sound, file);
	if (err)
		return (1);
    sound.format.bits = mpg123_encsize(sound.encoding) * BITS;
	if (sound.format.bits == 0)
		return (free(sound.buffer), mpg123_close(sound.mh),
			mpg123_delete(sound.mh), mpg123_exit(), ao_shutdown(), 0);
    sound.format.rate = sound.rate;
    sound.format.channels = sound.channels;
    sound.format.byte_format = AO_FMT_NATIVE;
    sound.format.matrix = NULL;
    sound.dev = ao_open_live(sound.driver, &sound.format, NULL);
	if (!sound.dev)
		return (free(sound.buffer), mpg123_close(sound.mh),
			mpg123_delete(sound.mh), mpg123_exit(), ao_shutdown(), 0);
    while (mpg123_read(sound.mh, sound.buffer, sound.buffer_size, &sound.done)
		== MPG123_OK)
        ao_play(sound.dev, (char *)sound.buffer, sound.done);
	free_sound(&sound);
    return (0);
}

int	play_sound(char *file)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		run_sound(file);
		exit(0);
	}
	return (pid);
}