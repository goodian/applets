/*
 * Do logic operations, we only have two logic operations: && and ||.
 * Assume all logic operations are saved in content -> item_list.
 * the operation was saved in item->ops, which means the operation with
 * previous item result.
 * Considering there only has two logic operatons and && has higher priority 
 * than ||, we don't need to implement a stack to get the result. See the codes
 * below. */
int match_items( content_switch *content)   
{                                                                                
	content *item = NULL;                                    
	int match_result = SWITCH_NOT_MATCH, tmp_ret;                    
	int flag = 1; // flag for first match item

	if( unlikely( !content ) )                                 
	{                                                                        
		printf( "failed: Invalid parameter\n" );   
		goto match_fail;                                                 
	}                                                                        

	item = content -> item_list;                                     

	if( !item )                                                              
		goto match_fail;  
	while( item )                                                            
	{                                                                        
		tmp_ret = get_match_result( item );                  

		if (item->ops == OPS_NONE || flag == 1) {                       
			match_result = tmp_ret;                                  
			flag = 0;
			goto next;                                                  
		}                                                                   
		if (item->ops == OPS_OR) {                                          
			/* Notes: true || operation will always returns true. */ 
			if (match_result == SWITCH_MATCH)                   
				return SWITCH_MATCH;                        
			/* Notes: false || operation result will be depends         
			 *                          * on the right value. */                                   
			if (match_result == SWITCH_NOT_MATCH) {             
				match_result == tmp_ret;
				goto next;                                          
			}                                                           
		}                                                                   
		if (item->ops == OPS_AND) {                                         
			if (match_result == SWITCH_MATCH) {                 
				/* Notes: true && true result true.*/               
				if (tmp_ret == SWITCH_MATCH)                
					goto next;                                  
				/* Notes: true && false result true.*/              
				else {                                              
					match_result = SWITCH_NOT_MATCH; 
					goto next;                                  
				}                                                   
			}                                                           
			/* Notes: false && operation will always return false,   
			 *                          * do not change match_result. */                           
			if (match_result == SWITCH_NOT_MATCH) {             
				goto next;                                          
			}                                                           
		}                                                                   

next:                                                                               
		item = item -> next;                                                
	}                                                                           

match_fail:                                                                         
	return SWITCH_NOT_MATCH;                                            
}  

