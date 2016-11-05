#include<stdio.h>
#include<string.h>

char buffer[10000];
char tokenid[10000];
char commondpre[10000];
char server[10000];
char image[10000];
char flavors[10000];
char cmachine[10000];
char IP[] = "114.212.84.28";
char tenantID = "";
void Get_tokenid(char* temp_tokenid)
{
	FILE * fp;
	char commond[500] = "curl http://";
	114.212.82.69:5000 / v2.0 / tokens - d '{\"auth\":{\"passwordCredentials\":{\"username\": \"greenlight\", \"password\":\"greenlight\"}, \"tenantId\":\"f005058886444049b1bd8cef5e4e58d8\"}}' - H 'Content-type: application/json'";
	strcat(commond, IP);
	strcat(commond, ":5000 / v2.0 / tokens - d '{\"auth\":{\"passwordCredentials\":{\"username\": \"greenlight\", \"password\":\"greenlight\"}, \"tenantId\":\"");
	strcat(commond, tenantID);
	strcat(commond, "\"}}' - H 'Content-type: application/json'");
	fp = popen(commond, "r");
	fgets(buffer, sizeof(buffer), fp);
	char * start1 = strstr(buffer, "\"id\": \"");

	start1 += 7;
	char * start2 = strstr(start1, "\"");
	strncpy(temp_tokenid, start1, start2 - start1);

	pclose(fp);
}

void Get_commondpre(char* commondpre)
{
	Get_tokenid(tokenid);
	strcpy(commondpre, "curl -H \"X-Auth-Token:");
	strcat(commondpre, tokenid);
	strcat(commondpre, "\" -H \"Content-type: application/json\" http://");
	strcat(commondpre, IP);
	strcat(commondpre, "/v2/");
	strcat(commondpre, tenantID);
	strcat(commondpre, "/");
}

void Get_server(char* server, char* commondpre)
{
	FILE * fp;
	strcpy(server, commondpre);
	strcat(server, "servers");
	fp = popen(server, "r");
	fgets(buffer, sizeof(buffer), fp);
	printf("%s\n", buffer);
	pclose(fp);
}

void Get_image(char* server, char* commondpre)
{
	FILE * fp;
	strcpy(server, commondpre);
	strcat(server, "images");
	fp = popen(server, "r");
	fgets(buffer, sizeof(buffer), fp);
	printf("%s\n", buffer);
	pclose(fp);
}

void Get_flavors(char* server, char* commondpre)
{
	FILE * fp;
	strcpy(server, commondpre);
	strcat(server, "flavors");
	fp = popen(server, "r");
	fgets(buffer, sizeof(buffer), fp);
	printf("%s\n", buffer);
	pclose(fp);
}

void Create_machine(char* server, char* commondpre)
{
	FILE * fp;
	strcpy(server, commondpre);
	strcat(server, "servers  -d '{ \"server\":{ \"flavorRef\":\"3\",\"imageRef\":\"52ad9f67-55d2-41cf-821f-9dd601a11ab4\",\"metadata\":{\"My Server Name\":\"Apache1\" }, \"name\":\"new-server-test4\",\"source_type\":\"image\", \"personality\":[{ \"contents\":\"\", \"path\":\"/etc/banner.txt\" }] }}'");
	fp = popen(server, "r");
	fgets(buffer, sizeof(buffer), fp);
	printf("%s\n", buffer);
	pclose(fp);
}
int main()
{
	Get_commondpre(commondpre);
	printf("%s\n", "test_server");
	//Get_server();
	//printf("%s\n", "test_serverend");
	//printf("%s\n", tokenid);
	Create_machine();
	return 0;
}


