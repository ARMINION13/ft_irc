#ifndef _CHANNEL
# define _CHANNEL

#include <iostream>
#include <vector>
#include <string>

class Channel {

    public:
        Channel( void );
        ~Channel( void );
        Channel( const Channel& other );

        int JoinClient( int client_sd, bool oprtor );
        bool PartClient( int client_sd ); //return false if not found
        void SetChannelConcept( std::string new_concept );

        std::string GetChannelConcept( void );
        void GetChannelConcept( std::string concept );
        std::vector<int> GetClients( void );
        std::vector<int> GetOperators( void );
        std::vector<int> GetNoOperatorClients( void );
        bool GetIfClientOperator( int client_sd );
        bool GetIfClientInChannel( int client_sd );
        bool CheckKey( std::string trying_key );

        //channel flags getters
        bool    GetP_Flag( void );
        bool    GetS_Flag( void );
        bool    GetI_Flag( void );
        bool    GetT_Flag( void );
        bool    GetN_Flag( void );
        bool    GetM_Flag( void );
        int     GetL_Flag( void );

        //channel flags setters
        void    GetP_Flag( bool P );
        void    GetS_Flag( bool S );
        void    GetI_Flag( bool I );
        void    GetT_Flag( bool T );
        void    GetN_Flag( bool N );
        void    GetM_Flag( bool M );
        void    GetL_Flag( int max );


    private:
        std::string         channel_concept;
        std::vector<int>    client_sd_list;
        std::vector<int>    oprtor_sd_list;

        std::string         channel_key;

        //channel flags 
        bool                private_channel;
        bool                secret_channel;
        bool                invite_only;
        bool                topic_opr_only;
        bool                out_msg_reject;
        bool                moderated_channel;
        int                 channel_max_users;
};

#endif
