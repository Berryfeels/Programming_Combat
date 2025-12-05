/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:36 by mcheragh          #+#    #+#             */
/*   Updated: 2025/09/08 20:39:05 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void play_audio(const char *file) {

	signal(SIGCHLD, SIG_IGN);
    pid_t pid = fork();
    if (pid == 0) {
        execl("/usr/bin/aplay", "aplay", file, (char *)NULL);
        perror("execl failed");
        _exit(1);
    }
    // Parent continues
}