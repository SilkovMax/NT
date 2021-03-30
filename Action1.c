Action1()
{
//	
	web_reg_save_param_ex(
        "ParamName=FirstCost", 
        "LB=Total Charge: $ ",               
        "RB= <BR/>",                           
        "Ordinal=1",                             
    LAST); 

   
    web_reg_find("Text=A First class ticket for",
                 "SaveCount=FirstClass",
                 LAST);

	
	
	web_url("Itinerary Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);
	
	
	 lr_output_message("Price first ticket = %d",atoi(lr_eval_string("{FirstCost}")));
	 lr_output_message("Number of ticket 1 class= %d",atoi(lr_eval_string("{FirstClass}")));
	
	return 0;
}
