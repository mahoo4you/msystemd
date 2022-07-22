/*

 msystemd Copyright (C) <2017>  <matthias holl>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>



 msystemd

 Control the systemd system and service manager

 www.mahoosoft.com

 gcc -o msystemd msystemd.c

 sudo ./msystemd

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum {
	lunitfiles,	
	shallloadunits,
	lsockets,
	start_daemon,
	stop_daemon,
	runlevel,
	status,
	daemon_status,
	show,
	show_daemon,
	list_dep,
	list_dep_daem,
	list_machines,
	list_machines_patt,
	list_jobs,
	list_jobs_patt,
	rescue,
	reboot,
	poweroff,
	bye
};

void scd() {	  
     char daemon[100];
     char command[100] = "sudo systemctl start ";
     char command_end[100] = ".service";
     char command_exec[100];
     printf("daemon:");	
     scanf("%s",daemon);
	  strcat(command,daemon);
	  strcat(command,command_end);
	  strcpy(command_exec,command);	  
	  printf("%s \n",command_exec);
	  system(command_exec);


}

void stcd() {	  
     char daemon[100];
     char command[100] = "sudo systemctl stop ";
     char command_end[100] = ".service";
     char command_exec[100];
     printf("daemon:");	
     scanf("%s",daemon);
	  strcat(command,daemon);
	  strcat(command,command_end);
	  strcpy(command_exec,command);	  
	  printf("%s \n",command_exec);
	  system(command_exec);


}

void chrunlevel() {	  
     char daemon[100];
     char command[100] = "sudo systemctl isolate ";
     char command_end[100] = ".target";
     char command_exec[100];
     printf("runlevel:");	
     scanf("%s",daemon);
	  strcat(command,daemon);
	  strcat(command,command_end);
	  strcpy(command_exec,command);	  
	  printf("%s \n",command_exec);
	  system(command_exec);


}

void dstat() {	  
     char daemon[100];
     char command[100] = "sudo systemctl status ";
     char command_exec[100];
     printf("daemon/device/dir:");	
     scanf("%s",daemon);
	  strcat(command,daemon);
	  strcpy(command_exec,command);	  
	  printf("%s \n",command_exec);
	  system(command_exec);


}

void shdm() {	  
     char daemon[100];
     char command[100] = "sudo systemctl show ";
     char command_exec[100];
     printf("daemon:");	
     scanf("%s",daemon);
	  strcat(command,daemon);
	  strcpy(command_exec,command);	  
	  printf("%s \n",command_exec);
	  system(command_exec);


}

void ldepdm() {	  
     char daemon[100];
     char command[100] = "sudo systemctl list-dependencies ";
     char command_exec[100];
     printf("daemon:");	
     scanf("%s",daemon);
	  strcat(command,daemon);
	  strcpy(command_exec,command);	  
	  printf("%s \n",command_exec);
	  system(command_exec);


}

void lmach() {	  
     char daemon[100];
     char command[100] = "sudo systemctl list-machines ";
     char command_exec[100];
     printf("pattern:");	
     scanf("%s",daemon);
	  strcat(command,daemon);
	  strcpy(command_exec,command);	  
	  printf("%s \n",command_exec);
	  system(command_exec);


}

void ljobs() {	  
     char daemon[100];
     char command[100] = "sudo systemctl list-jobs ";
     char command_exec[100];
     printf("pattern:");	
     scanf("%s",daemon);
	  strcat(command,daemon);
	  strcpy(command_exec,command);	  
	  printf("%s \n",command_exec);
	  system(command_exec);


}


int main(void) {
	int menu;
	do {

		printf("\n");
		printf("This is free software! GNU General Public License \n");
		printf("This program comes with ABSOLUTELY NO WARRANTY \n");
		printf("msystemd Control the systemd system and service manager\n");
		printf("\n");
		printf("-%d-  list unit files\n", lunitfiles);
		printf("-%d-  show all loaded units\n", shallloadunits);
		printf("-%d-  list socket units\n", lsockets);
		printf("-%d-  start daemon\n", start_daemon);
		printf("-%d-  stop daemon\n", stop_daemon);
		printf("-%d-  change runlevel\n", runlevel);
		printf("-%d-  status\n", status);
		printf("-%d-  daemon/device/dir status\n", daemon_status);
		printf("-%d-  show\n", show);
		printf("-%d-  show daemon\n", show_daemon);
		printf("-%d-  list dependencies\n", list_dep);
		printf("-%d-  list dependencies daemon\n", list_dep_daem);
		printf("-%d-  list machines\n", list_machines);
		printf("-%d-  list machines pattern\n", list_machines_patt);
		printf("-%d-  list jobs\n", list_jobs);
		printf("-%d-  list jobs pattern\n", list_jobs_patt);
		printf("-%d-  rescue\n", rescue);																
		printf("-%d-  reboot\n", reboot);																
		printf("-%d-  poweroff\n", poweroff);																																
		printf("-%d-  quit\n", bye);
		printf("----> ");

		do {
			scanf("%d", &menu);
		} while (getchar() != '\n');

		switch (menu) {
			
		case lunitfiles:
			system("sudo systemctl list-unit-files");
			break;
		
		case shallloadunits:
			system("sudo systemctl -all");
			break;
			
		case lsockets:
			system("sudo systemctl list-sockets");
			break;	
			
		case rescue:
			system("sudo systemctl isolate rescue.target");
			break;
			
		case reboot:
			system("sudo systemctl isolate reboot.target");
			break;		
			
		case poweroff:
			system("sudo systemctl isolate poweroff.target");
			break;				
		
		case start_daemon:
			scd();
			break;
			
		case stop_daemon:
			stcd();
			break;
			
		case runlevel:
			chrunlevel();
			break;				
			
		case status:
			system("sudo systemctl status");
			break;
			
		case daemon_status:
			dstat();
			break;
			
		case show:
			system("sudo systemctl show");
			break;
			
		case show_daemon:
			shdm();
			break;
			
		case list_dep:
			system("sudo systemctl list-dependencies");
			break;
			
		case list_dep_daem:
			ldepdm();
			break;
			
		case list_machines:
			system("sudo systemctl list-machines");
			break;
			
		case list_machines_patt:
			lmach();
			break;
			
		case list_jobs:
			system("sudo systemctl list-jobs");
			break;
			
		case list_jobs_patt:
			ljobs();
			break;																

		}
	} while (menu != bye);
	printf("bye... msystemd\n");
	printf("GNU General Public License\n\n\n");
	return EXIT_SUCCESS;
}
