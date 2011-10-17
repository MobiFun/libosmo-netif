#ifndef _OSMO_NETIF_IPA_H_
#define _OSMO_NETIF_IPA_H_

struct ipa_head {
	uint16_t len;	/* network byte order */
	uint8_t proto;
	uint8_t data[0];
} __attribute__ ((packed));

/* IPA protocols. */
#define IPAC_PROTO_RSL		0x00
#define IPAC_PROTO_IPACCESS	0xfe
#define IPAC_PROTO_SCCP		0xfd
#define IPAC_PROTO_OML		0xff
#define IPAC_PROTO_OSMO		0xee	/* OpenBSC extension. */
#define IPAC_PROTO_MGCP_OLD	0xfc	/* OpenBSC extension. */

struct ipa_head_ext {
	uint8_t proto;
	uint8_t data[0];
} __attribute__ ((packed));

/* Protocol extensions. */
#define IPAC_PROTO_EXT_CTRL	0x00
#define IPAC_PROTO_EXT_MGCP	0x01
#define IPAC_PROTO_EXT_LAC	0x02

/* Message types. */
#define IPAC_MSGT_PING		0x00
#define IPAC_MSGT_PONG		0x01
#define IPAC_MSGT_ID_GET	0x04
#define IPAC_MSGT_ID_RESP	0x05
#define IPAC_MSGT_ID_ACK	0x06
#define IPAC_MSGT_SCCP_OLD	0xff	/* OpenBSC extension */

enum ipaccess_id_tags {
        IPAC_IDTAG_SERNR                = 0x00,
        IPAC_IDTAG_UNITNAME             = 0x01,
        IPAC_IDTAG_LOCATION1            = 0x02,
        IPAC_IDTAG_LOCATION2            = 0x03,
        IPAC_IDTAG_EQUIPVERS            = 0x04,
        IPAC_IDTAG_SWVERSION            = 0x05,
        IPAC_IDTAG_IPADDR               = 0x06,
        IPAC_IDTAG_MACADDR              = 0x07,
        IPAC_IDTAG_UNIT                 = 0x08,
};

struct msgb *osmo_ipa_msg_alloc(int headroom);
void osmo_ipa_msg_push_header(struct msgb *msg, uint8_t proto);
int osmo_ipa_msg_recv(int fd, struct msgb *msg);

#endif
