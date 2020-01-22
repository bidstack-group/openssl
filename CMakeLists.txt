cmake_minimum_required(VERSION 3.14)
project(open_ssl C ASM)


#highly unlikely that these directories would exist on any system
set(OPENSSLDIR "/tēmр/123")
set(ENGINESDIR "/tēmр/en123")

set(COMMON_ssl_SRCS
    ssl/ssl_rsa.c ssl/statem/statem_srvr.c
    ssl/s3_enc.c ssl/d1_srtp.c
    ssl/statem/statem.c ssl/ssl_err.c
    ssl/statem/extensions.c ssl/record/dtls1_bitmap.c
    ssl/ssl_init.c ssl/s3_msg.c
    ssl/ssl_txt.c ssl/ssl_stat.c
    ssl/ssl_utst.c ssl/record/ssl3_buffer.c
    ssl/t1_enc.c ssl/record/rec_layer_d1.c
    ssl/pqueue.c ssl/ssl_lib.c
    ssl/t1_lib.c ssl/statem/statem_dtls.c
    ssl/bio_ssl.c ssl/ssl_ciph.c
    ssl/tls_srp.c ssl/d1_lib.c
    ssl/statem/extensions_srvr.c ssl/ssl_cert.c
    ssl/statem/statem_lib.c ssl/packet.c
    ssl/methods.c ssl/record/rec_layer_s3.c
    ssl/d1_msg.c ssl/t1_trce.c
    ssl/statem/statem_clnt.c ssl/tls13_enc.c
    ssl/s3_lib.c ssl/ssl_asn1.c
    ssl/statem/extensions_clnt.c ssl/record/ssl3_record.c
    ssl/ssl_conf.c ssl/ssl_sess.c
    ssl/statem/extensions_cust.c ssl/ssl_mcnf.c
    ssl/record/ssl3_record_tls13.c ssl/s3_cbc.c
)

set(COMMON_crypto_SRCS
    crypto/bn/bn_ctx.c crypto/rsa/rsa_gen.c crypto/conf/conf_sap.c crypto/ec/ec_mult.c crypto/x509/x_exten.c crypto/ec/ec_check.c
    crypto/evp/pmeth_fn.c crypto/ec/ecp_oct.c crypto/hmac/hmac.c crypto/bn/bn_lib.c crypto/ui/ui_null.c crypto/des/set_key.c
    crypto/bn/bn_mpi.c crypto/rand/rand_lib.c crypto/pem/pem_all.c crypto/ec/ecdh_ossl.c crypto/asn1/tasn_dec.c crypto/evp/m_mdc2.c
    crypto/comp/comp_err.c crypto/ct/ct_x509v3.c crypto/pem/pem_err.c crypto/o_dir.c crypto/ocsp/ocsp_vfy.c crypto/ocsp/ocsp_prn.c
    crypto/x509/x509_req.c crypto/evp/m_null.c crypto/srp/srp_lib.c crypto/sha/sha512.c crypto/ct/ct_oct.c crypto/rsa/rsa_saos.c
    crypto/asn1/x_spki.c crypto/x509/x509cset.c crypto/pkcs12/p12_key.c crypto/asn1/x_pkey.c crypto/des/qud_cksm.c crypto/objects/obj_err.c
    crypto/o_init.c crypto/des/str2key.c crypto/asn1/p5_pbev2.c crypto/x509/by_dir.c crypto/pem/pem_x509.c crypto/aes/aes_ofb.c
    crypto/asn1/asn_pack.c crypto/bn/bn_sqrt.c crypto/x509v3/v3_ia5.c crypto/evp/m_sigver.c crypto/evp/evp_key.c crypto/x509/x509_obj.c
    crypto/bio/bf_lbuf.c crypto/asn1/tasn_scn.c crypto/x509v3/v3_bcons.c crypto/store/store_register.c crypto/ct/ct_prn.c crypto/pkcs12/p12_p8d.c
    crypto/cversion.c crypto/conf/conf_mall.c crypto/x509v3/v3_conf.c crypto/dsa/dsa_ameth.c crypto/evp/evp_enc.c crypto/dh/dh_err.c
    crypto/x509/x509_meth.c crypto/bn/bn_depr.c crypto/ts/ts_req_print.c crypto/asn1/a_utctm.c crypto/buffer/buf_err.c crypto/ec/ec_ameth.c
    crypto/x509v3/v3_skey.c crypto/evp/e_rc5.c crypto/o_fips.c crypto/evp/e_aes.c crypto/rsa/rsa_pk1.c crypto/ec/ec_oct.c
    crypto/ct/ct_vfy.c crypto/ec/curve448/curve448_tables.c crypto/objects/obj_lib.c crypto/bn/bn_srp.c crypto/store/loader_file.c crypto/asn1/i2d_pr.c
    crypto/ec/ecp_nistp521.c crypto/async/arch/async_posix.c crypto/objects/obj_dat.c crypto/cryptlib.c crypto/des/ofb64ede.c crypto/rc2/rc2cfb64.c
    crypto/pkcs12/p12_sbag.c crypto/x509/x509name.c crypto/dsa/dsa_prn.c crypto/x509/x509_vfy.c crypto/ui/ui_err.c crypto/rc2/rc2_ecb.c
    crypto/evp/e_idea.c crypto/ocsp/v3_ocsp.c crypto/asn1/asn_moid.c crypto/siphash/siphash_pmeth.c crypto/ec/ecp_nistp224.c crypto/x509/x_all.c
    crypto/x509v3/v3_prn.c crypto/x509/x509_r2x.c crypto/dh/dh_prn.c crypto/asn1/a_octet.c crypto/rc2/rc2_cbc.c crypto/pkcs12/p12_init.c
    crypto/ocsp/ocsp_ht.c crypto/des/ofb_enc.c crypto/des/cfb64enc.c crypto/evp/e_aes_cbc_hmac_sha1.c crypto/bn/bn_const.c crypto/des/cbc_cksm.c
    crypto/ec/ec2_smpl.c crypto/asn1/n_pkey.c crypto/ec/ecdsa_sign.c crypto/evp/m_ripemd.c crypto/pem/pem_lib.c crypto/bn/bn_x931p.c
    crypto/blake2/m_blake2s.c crypto/ec/ec_kmeth.c crypto/cms/cms_dd.c crypto/ocsp/ocsp_asn.c crypto/x509/x_crl.c crypto/evp/m_wp.c
    crypto/dh/dh_key.c crypto/bio/bio_lib.c crypto/dsa/dsa_err.c crypto/bf/bf_cfb64.c crypto/cms/cms_pwri.c crypto/cms/cms_sd.c
    crypto/modes/cfb128.c crypto/evp/bio_ok.c crypto/x509v3/pcy_node.c crypto/asn1/asn1_par.c crypto/bn/bn_shift.c crypto/bn/bn_mul.c
    crypto/pem/pem_sign.c crypto/rand/randfile.c crypto/kdf/kdf_err.c crypto/pkcs7/pk7_asn1.c crypto/evp/c_allc.c crypto/x509v3/v3_lib.c
    crypto/dso/dso_lib.c crypto/cms/cms_smime.c crypto/blake2/blake2b.c crypto/lhash/lhash.c crypto/bn/bn_mont.c crypto/x509v3/v3_asid.c
    crypto/threads_none.c crypto/sha/sha1dgst.c crypto/rc2/rc2_skey.c crypto/ec/ecx_meth.c crypto/ec/curve448/eddsa.c crypto/des/ecb_enc.c
    crypto/rsa/rsa_chk.c crypto/bio/bf_null.c crypto/dso/dso_win32.c crypto/asn1/a_int.c crypto/async/arch/async_win.c crypto/modes/cts128.c
    crypto/bio/b_dump.c crypto/evp/e_xcbc_d.c crypto/evp/e_old.c crypto/pkcs12/p12_asn.c crypto/evp/evp_cnf.c crypto/asn1/t_pkey.c
    crypto/bio/bss_bio.c crypto/evp/e_null.c crypto/x509/x509type.c crypto/asn1/bio_asn1.c crypto/ts/ts_rsp_verify.c crypto/evp/c_alld.c
    crypto/ts/ts_verify_ctx.c crypto/x509/t_x509.c crypto/stack/stack.c crypto/dso/dso_dl.c crypto/ct/ct_err.c crypto/ct/ct_log.c
    crypto/cast/c_enc.c crypto/rand/rand_win.c crypto/rsa/rsa_meth.c crypto/x509v3/v3err.c crypto/evp/evp_err.c crypto/asn1/x_info.c
    crypto/kdf/hkdf.c crypto/ct/ct_b64.c crypto/x509v3/pcy_data.c crypto/mem_sec.c crypto/modes/wrap128.c crypto/asn1/tasn_fre.c
    crypto/bn/bn_mod.c crypto/ocsp/ocsp_ext.c crypto/x509/x509_err.c crypto/x509/by_file.c crypto/asn1/t_spki.c crypto/cms/cms_asn1.c
    crypto/cast/c_cfb64.c crypto/rsa/rsa_ssl.c crypto/bf/bf_skey.c crypto/asn1/x_long.c crypto/seed/seed.c crypto/asn1/x_bignum.c
    crypto/sm2/sm2_pmeth.c crypto/bn/bn_add.c crypto/asn1/d2i_pr.c crypto/getenv.c crypto/x509/x509_def.c crypto/rsa/rsa_sign.c
    crypto/comp/comp_lib.c crypto/x509v3/v3_alt.c crypto/evp/p_dec.c crypto/x509v3/v3_utl.c crypto/evp/p_verify.c crypto/bio/bf_buff.c
    crypto/rsa/rsa_oaep.c crypto/pkcs12/p12_crt.c crypto/ec/curve448/curve448.c crypto/err/err_all.c crypto/asn1/a_dup.c crypto/rsa/rsa_pmeth.c
    crypto/evp/p_seal.c crypto/x509/x509_ext.c crypto/bio/bf_nbio.c crypto/aes/aes_wrap.c crypto/asn1/a_verify.c crypto/aes/aes_ecb.c
    crypto/x509/t_crl.c crypto/evp/e_bf.c crypto/asn1/a_strex.c crypto/rsa/rsa_asn1.c crypto/x509/x_req.c crypto/evp/e_camellia.c
    crypto/pkcs12/pk12err.c crypto/bf/bf_ecb.c crypto/siphash/siphash_ameth.c crypto/pkcs12/p12_attr.c crypto/cmac/cmac.c crypto/asn1/x_int64.c
    crypto/evp/evp_pbe.c crypto/x509v3/v3_pcons.c crypto/evp/m_md4.c crypto/evp/digest.c crypto/asn1/f_string.c crypto/x509v3/v3_genn.c
    crypto/asn1/asn_mstbl.c crypto/bn/bn_intern.c crypto/modes/ofb128.c crypto/modes/xts128.c crypto/cmac/cm_ameth.c crypto/x509v3/pcy_lib.c
    crypto/rc2/rc2ofb64.c crypto/cast/c_ofb64.c crypto/ec/curve25519.c crypto/asn1/a_strnid.c crypto/x509v3/v3_extku.c crypto/ec/curve448/arch_32/f_impl.c
    crypto/bio/bio_meth.c crypto/store/store_init.c crypto/bn/bn_exp2.c crypto/asn1/evp_asn1.c crypto/async/arch/async_null.c crypto/x509/x509_cmp.c
    crypto/dh/dh_rfc7919.c crypto/pem/pvkfmt.c crypto/modes/ctr128.c crypto/evp/m_md5_sha1.c crypto/seed/seed_cfb.c crypto/idea/i_ecb.c
    crypto/asn1/tasn_typ.c crypto/evp/pbe_scrypt.c crypto/x509/x509_v3.c crypto/asn1/a_sign.c crypto/ts/ts_lib.c crypto/asn1/tasn_enc.c
    crypto/pkcs7/pk7_attr.c crypto/evp/bio_enc.c crypto/x509v3/v3_tlsf.c crypto/evp/e_sm4.c crypto/evp/e_rc2.c crypto/evp/cmeth_lib.c
    crypto/cms/cms_lib.c crypto/des/xcbc_enc.c crypto/sha/sha256.c crypto/blake2/m_blake2b.c crypto/pkcs12/p12_npas.c crypto/cms/cms_enc.c
    crypto/ripemd/rmd_dgst.c crypto/x509v3/pcy_map.c crypto/ec/ecp_nistp256.c crypto/bio/b_sock2.c crypto/bn/bn_print.c crypto/bio/bss_acpt.c
    crypto/aes/aes_misc.c crypto/sm2/sm2_crypt.c crypto/asn1/a_d2i_fp.c crypto/x509v3/v3_bitst.c crypto/evp/encode.c crypto/asn1/x_val.c
    crypto/async/async.c crypto/x509/x509spki.c crypto/md5/md5_one.c crypto/conf/conf_ssl.c crypto/ts/ts_asn1.c crypto/evp/pmeth_gn.c
    crypto/md4/md4_one.c crypto/bn/bn_gcd.c crypto/aes/aes_core.c crypto/ec/ec2_oct.c crypto/ct/ct_policy.c crypto/objects/o_names.c
    crypto/hmac/hm_ameth.c crypto/ec/ec_pmeth.c crypto/asn1/asn_mime.c crypto/des/pcbc_enc.c crypto/asn1/p8_pkey.c crypto/conf/conf_err.c
    crypto/x509v3/v3_pcia.c crypto/bn/bn_nist.c crypto/bn/bn_recp.c crypto/rsa/rsa_none.c crypto/rsa/rsa_prn.c crypto/dsa/dsa_vrf.c
    crypto/dh/dh_kdf.c crypto/rand/rand_err.c crypto/bn/bn_sqr.c crypto/pkcs12/p12_mutl.c crypto/sha/sha1_one.c crypto/blake2/blake2s.c
    crypto/asn1/a_gentm.c crypto/md4/md4_dgst.c crypto/kdf/scrypt.c crypto/bio/bss_dgram.c crypto/bn/bn_prime.c crypto/store/store_err.c
    crypto/evp/e_chacha20_poly1305.c crypto/aes/aes_ige.c crypto/ts/ts_req_utils.c crypto/x509/x509rset.c crypto/conf/conf_def.c crypto/ec/ecp_mont.c
    crypto/evp/e_rc4.c crypto/x509v3/v3_sxnet.c crypto/x509/x509_d2.c crypto/mdc2/mdc2dgst.c crypto/evp/e_des.c crypto/pem/pem_xaux.c
    crypto/rsa/rsa_ossl.c crypto/camellia/cmll_cfb.c crypto/kdf/tls1_prf.c crypto/asn1/asn1_item_list.c crypto/bf/bf_ofb64.c crypto/bio/bss_file.c
    crypto/pkcs12/p12_crpt.c crypto/ec/ec_key.c crypto/rand/drbg_ctr.c crypto/ec/curve448/f_generic.c crypto/x509v3/v3_pci.c crypto/ts/ts_err.c
    crypto/des/rand_key.c crypto/cms/cms_kari.c crypto/bn/bn_exp.c crypto/o_fopen.c crypto/ocsp/ocsp_cl.c crypto/store/store_strings.c
    crypto/idea/i_cfb64.c crypto/ocsp/ocsp_srv.c crypto/dsa/dsa_key.c crypto/dh/dh_meth.c crypto/ts/ts_rsp_utils.c crypto/bio/bss_log.c
    crypto/txt_db/txt_db.c crypto/ebcdic.c crypto/rsa/rsa_err.c crypto/asn1/a_digest.c crypto/siphash/siphash.c crypto/pkcs7/pk7_lib.c
    crypto/dh/dh_pmeth.c crypto/dh/dh_lib.c crypto/pem/pem_pkey.c crypto/rsa/rsa_lib.c crypto/ts/ts_rsp_sign.c crypto/des/des_enc.c
    crypto/evp/p_lib.c crypto/aria/aria.c crypto/o_time.c crypto/evp/m_md5.c crypto/asn1/p5_scrypt.c crypto/conf/conf_lib.c
    crypto/cast/c_ecb.c crypto/async/async_wait.c crypto/asn1/p5_pbe.c crypto/evp/p_open.c crypto/x509v3/v3_pmaps.c crypto/x509/x_name.c
    crypto/rsa/rsa_x931.c crypto/x509v3/v3_addr.c crypto/rsa/rsa_crpt.c crypto/x509v3/v3_crld.c crypto/bio/bio_err.c crypto/dh/dh_check.c
    crypto/pkcs12/p12_utl.c crypto/camellia/cmll_ofb.c crypto/rsa/rsa_ameth.c crypto/asn1/x_algor.c crypto/ec/eck_prn.c crypto/ui/ui_openssl.c
    crypto/bn/bn_gf2m.c crypto/evp/bio_b64.c crypto/cpt_err.c crypto/threads_win.c crypto/des/ecb3_enc.c crypto/camellia/cmll_ecb.c
    crypto/bio/bss_mem.c crypto/bio/b_print.c crypto/ec/ec_lib.c crypto/ec/ecdsa_vrf.c crypto/modes/gcm128.c crypto/cmac/cm_pmeth.c
    crypto/rand/drbg_lib.c crypto/asn1/asn1_err.c crypto/dso/dso_vms.c crypto/asn1/a_time.c crypto/asn1/nsseq.c crypto/evp/evp_pkey.c
    crypto/seed/seed_cbc.c crypto/des/fcrypt.c crypto/err/err_prn.c crypto/x509v3/v3_enum.c crypto/ripemd/rmd_one.c crypto/whrlpool/wp_dgst.c
    crypto/dsa/dsa_meth.c crypto/pkcs12/p12_kiss.c crypto/cms/cms_err.c crypto/ui/ui_lib.c crypto/comp/c_zlib.c crypto/ts/ts_rsp_print.c
    crypto/x509v3/v3_int.c crypto/evp/names.c crypto/evp/bio_md.c crypto/x509v3/v3_info.c crypto/buffer/buffer.c crypto/evp/m_md2.c
    crypto/rand/rand_vms.c crypto/x509/x509_vpm.c crypto/asn1/a_mbstr.c crypto/evp/m_sha3.c crypto/mem.c crypto/rsa/rsa_pss.c
    crypto/dsa/dsa_ossl.c crypto/pkcs12/p12_add.c crypto/des/cfb_enc.c crypto/poly1305/poly1305_ameth.c crypto/x509v3/v3_purp.c crypto/srp/srp_vfy.c
    crypto/pkcs7/pk7_mime.c crypto/evp/p5_crpt.c crypto/rand/rand_unix.c crypto/cms/cms_ess.c crypto/ec/ecdh_kdf.c crypto/bn/bn_div.c
    crypto/idea/i_ofb64.c crypto/modes/ccm128.c crypto/ec/ec_curve.c crypto/evp/e_seed.c crypto/dso/dso_openssl.c crypto/asn1/a_type.c
    crypto/asn1/tasn_new.c crypto/pem/pem_oth.c crypto/pkcs7/pk7_smime.c crypto/evp/m_sha1.c crypto/cms/cms_env.c crypto/bio/bss_null.c
    crypto/evp/e_rc4_hmac_md5.c crypto/asn1/ameth_lib.c crypto/ec/ec_asn1.c crypto/asn1/i2d_pu.c crypto/asn1/t_bitst.c crypto/x509v3/v3_pku.c
    crypto/ec/ecp_nist.c crypto/ex_data.c crypto/evp/e_des3.c crypto/dsa/dsa_gen.c crypto/pkcs7/bio_pk7.c crypto/pkcs12/p12_p8e.c
    crypto/bio/bss_fd.c crypto/asn1/a_utf8.c crypto/x509v3/v3_akeya.c crypto/evp/p_sign.c crypto/x509/t_req.c crypto/dsa/dsa_asn1.c
    crypto/sm2/sm2_err.c crypto/ct/ct_sct_ctx.c crypto/x509v3/v3_admis.c crypto/mdc2/mdc2_one.c crypto/evp/e_cast.c crypto/sm2/sm2_sign.c
    crypto/objects/obj_xref.c crypto/dh/dh_gen.c crypto/md5/md5_dgst.c crypto/dso/dso_err.c crypto/x509/x509_set.c crypto/asn1/a_print.c
    crypto/sm4/sm4.c crypto/bio/bio_cb.c crypto/threads_pthread.c crypto/poly1305/poly1305.c crypto/cms/cms_att.c crypto/des/ofb64enc.c
    crypto/asn1/a_object.c crypto/evp/p_enc.c crypto/asn1/bio_ndef.c crypto/des/cfb64ede.c crypto/asn1/x_sig.c crypto/poly1305/poly1305_pmeth.c
    crypto/ocsp/ocsp_lib.c crypto/lhash/lh_stats.c crypto/rsa/rsa_depr.c crypto/cms/cms_io.c crypto/ocsp/ocsp_err.c crypto/rsa/rsa_mp.c
    crypto/bn/bn_kron.c crypto/async/async_err.c crypto/asn1/asn1_lib.c crypto/dso/dso_dlfcn.c crypto/ec/ec_cvt.c crypto/x509v3/v3_cpols.c
    crypto/rsa/rsa_x931g.c crypto/evp/e_aria.c crypto/pkcs7/pk7_doit.c crypto/uid.c crypto/evp/p5_crpt2.c crypto/camellia/cmll_misc.c
    crypto/x509/x_pubkey.c crypto/x509/x509_trs.c crypto/dsa/dsa_depr.c crypto/dh/dh_depr.c crypto/x509/x_x509.c crypto/x509v3/pcy_tree.c
    crypto/ui/ui_util.c crypto/o_str.c crypto/asn1/f_int.c crypto/conf/conf_mod.c crypto/asn1/tasn_prn.c crypto/ct/ct_sct.c
    crypto/conf/conf_api.c crypto/cast/c_skey.c crypto/x509/x509_att.c crypto/aes/aes_cbc.c crypto/dsa/dsa_lib.c crypto/asn1/d2i_pu.c
    crypto/pkcs12/p12_decr.c crypto/cms/cms_cd.c crypto/dh/dh_ameth.c crypto/pkcs7/pkcs7err.c crypto/sm3/m_sm3.c crypto/sm3/sm3.c
    crypto/des/cbc_enc.c crypto/x509v3/pcy_cache.c crypto/evp/evp_lib.c crypto/dh/dh_rfc5114.c crypto/rand/rand_egd.c crypto/err/err.c
    crypto/ec/ecdsa_ossl.c crypto/ctype.c crypto/camellia/cmll_ctr.c crypto/dsa/dsa_sign.c crypto/x509/x509_lu.c crypto/x509/x_attrib.c
    crypto/bio/bss_sock.c crypto/evp/e_aes_cbc_hmac_sha256.c crypto/bio/bss_conn.c crypto/seed/seed_ofb.c crypto/bio/b_sock.c crypto/ec/ecp_nistputil.c
    crypto/bn/bn_word.c crypto/bn/bn_dh.c crypto/pem/pem_pk8.c crypto/asn1/tasn_utl.c crypto/asn1/asn1_gen.c crypto/dsa/dsa_pmeth.c
    crypto/asn1/a_bitstr.c crypto/x509/x509_txt.c crypto/ec/curve448/scalar.c crypto/ec/ecp_smpl.c crypto/aes/aes_cfb.c crypto/x509v3/v3_akey.c
    crypto/bio/b_addr.c crypto/modes/cbc128.c crypto/seed/seed_ecb.c crypto/bn/bn_err.c crypto/ts/ts_conf.c crypto/bn/bn_rand.c
    crypto/idea/i_cbc.c crypto/hmac/hm_pmeth.c crypto/idea/i_skey.c crypto/bf/bf_enc.c crypto/asn1/a_i2d_fp.c crypto/pem/pem_info.c
    crypto/x509v3/v3_ncons.c crypto/ec/ec_err.c crypto/store/store_lib.c crypto/evp/pmeth_lib.c crypto/dh/dh_asn1.c crypto/init.c
    crypto/bn/bn_blind.c crypto/ec/ec_print.c crypto/mem_dbg.c crypto/des/fcrypt_b.c crypto/x509/x_x509a.c crypto/modes/ocb128.c
)

set(crypto_SRC_android_ios
    crypto/engine/eng_all.c crypto/rc4/rc4_enc.c crypto/camellia/camellia.c 
    crypto/engine/eng_rdrand.c crypto/engine/tb_cipher.c crypto/camellia/cmll_cbc.c 
    crypto/engine/eng_cnf.c crypto/engine/eng_openssl.c crypto/engine/tb_rand.c 
    crypto/engine/eng_err.c crypto/engine/tb_eckey.c crypto/engine/eng_init.c 
    crypto/chacha/chacha_enc.c crypto/engine/eng_lib.c crypto/engine/eng_dyn.c 
    crypto/engine/eng_ctrl.c crypto/engine/eng_list.c crypto/engine/tb_pkmeth.c 
    crypto/engine/eng_pkey.c crypto/sha/keccak1600.c crypto/engine/tb_rsa.c 
    crypto/engine/tb_dsa.c crypto/mem_clr.c crypto/bn/bn_asm.c 
    crypto/engine/tb_dh.c crypto/engine/tb_asnmth.c crypto/engine/eng_table.c 
    crypto/engine/eng_fat.c crypto/whrlpool/wp_block.c crypto/engine/tb_digest.c crypto/rc4/rc4_skey.c
)

function(set_clang_unused) 
    if(CMAKE_C_COMPILER_ID MATCHES "Clang")
        #suppresses warnings for incompatible defines and flags (-MT, -MF) when compiling assembly files
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Qunused-arguments" PARENT_SCOPE)
        set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -Qunused-arguments" PARENT_SCOPE)
    endif(CMAKE_C_COMPILER_ID MATCHES "Clang")
endfunction(set_clang_unused) 

function(generate_configdata ARCH)
    message("Configuring configdata.pm for \"${ARCH}\"")
    execute_process(COMMAND ${PERL_EXECUTABLE} Configure ${ARCH}  ${ARGV1}
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE temp
            ERROR_VARIABLE error
    )
    if(error)
        message(FATAL_ERROR("Error while generating configdata.pm for ${ARCH}: ${error}"))
    endif(error)
endfunction(generate_configdata)

function(generate_mkbuildinf ARG ARCH)
    message("Generating mkbuildinf for ${ARCH}")

    set(Args "${ARG} ${CMAKE_C_FLAGS}")
    if(${CMAKE_BUILD_TYPE} MATCHES Debug)
        set(Args "${Args} ${CMAKE_C_FLAGS_RELEASE}")
    elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
        set(Args "${Args} ${CMAKE_C_FLAGS_RELEASE}")
    endif(${CMAKE_BUILD_TYPE} MATCHES Debug)

    execute_process(COMMAND ${PERL_EXECUTABLE} util/mkbuildinf.pl ${Args} ${ARCH}
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        OUTPUT_FILE crypto/buildinf.h
        ERROR_VARIABLE error)
    if(error)
        message(FATAL_ERROR("Error while generating mkbuildinf for ${ARCH}: ${error}"))
    endif(error)
endfunction(generate_mkbuildinf)

function(pls_to_asms PLs ASMs ARG ARCH)
    list(LENGTH ASMs asms_len)
    list(LENGTH PLs pls_len)

    if(NOT ${pls_len} EQUAL ${asms_len})
        message(FATAL_ERROR("Length of list of scripts (${pls_len}) is not equal to length of a list of .s files (${asms_len})."))
    endif(NOT ${pls_len} EQUAL ${asms_len})

    math(EXPR len "${pls_len}-1")
    foreach(idx RANGE ${len})
        list(GET PLs ${idx} pl)
        list(GET ASMs ${idx} asm)
        message("Running \"${pl}\" to get \"${asm}\" (${ARG})")
        execute_process(COMMAND ${PERL_EXECUTABLE}
            ${pl} ${ARG} ${asm}
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE temp
            ERROR_VARIABLE error
        )
        if(error)
            message(FATAL_ERROR("Error while generating ${pl} -> ${asm}: ${error}"))
        endif(error)
    endforeach()
endfunction(pls_to_asms)

function(generate_headers arch)
        foreach(el crypto/include/internal/bn_conf.h;crypto/include/internal/dso_conf.h;include/openssl/opensslconf.h)
            message("Generating ${el} for ${arch}")
            execute_process(COMMAND ${PERL_EXECUTABLE}
                "-I${CMAKE_CURRENT_LIST_DIR}" -Mconfigdata "util/dofile.pl" "-oMakefile" ${el}.in
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                OUTPUT_FILE ${el}
                ERROR_VARIABLE error)
            if(error)
                message(FATAL_ERROR("Error while generating: ${error}"))
            endif(error)
        endforeach()
endfunction(generate_headers)

if(CMAKE_OSX_SYSROOT MATCHES iPhoneSimulator)

    set(arch "iossimulator-xcrun")
    message("Building ${arch}")

    find_program(PERL_EXECUTABLE perl)
    if(NOT PERL_EXECUTABLE)
        message(FATAL_ERROR("Perl not found"))
    endif(NOT PERL_EXECUTABLE)

    generate_configdata(${arch} no-asm)
    generate_mkbuildinf("xcrun -sdk iphonesimulator cc -fPIC -DOPENSSL_PIC -D_REENTRANT" "iossimulator-xcrun")
    generate_headers(${arch})
        
    add_library(ssl STATIC ${COMMON_ssl_SRCS})
    target_include_directories(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
    target_compile_definitions(ssl PRIVATE  ENGINESDIR=${ENGINESDIR} _REENTRANT OPENSSLDIR=${OPENSSLDIR} OPENSSL_PIC)
    
    set(crypto_SRCS ${COMMON_crypto_SRCS}
        crypto/camellia/cmll_cbc.c crypto/mem_clr.c crypto/whrlpool/wp_block.c
        crypto/sha/keccak1600.c crypto/rc4/rc4_skey.c crypto/bn/bn_asm.c
        crypto/rc4/rc4_enc.c crypto/chacha/chacha_enc.c crypto/camellia/camellia.c
    )

    add_library(crypto STATIC ${crypto_SRCS})
    target_include_directories(crypto PRIVATE crypto/modes ${CMAKE_CURRENT_SOURCE_DIR} crypto/ec/curve448/arch_32 crypto/include crypto/ec/curve448 crypto include)
    target_compile_definitions(crypto PRIVATE  ENGINESDIR=${ENGINESDIR} _REENTRANT OPENSSLDIR=${OPENSSLDIR} OPENSSL_PIC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -mios-version-min=7.0.0")
    
elseif(CMAKE_OSX_SYSROOT MATCHES MacOSX)

    set(arch "darwin64-x86_64-cc")
    message("Building ${arch}")

    find_program(PERL_EXECUTABLE perl)
    if(NOT PERL_EXECUTABLE)
        message(FATAL_ERROR("Perl not found"))
    endif(NOT PERL_EXECUTABLE)

    generate_configdata(${arch})
    generate_mkbuildinf("clang -arch x86_64 -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_CPUID_OBJ -DOPENSSL_IA32_SSE2 -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_MONT5 -DOPENSSL_BN_ASM_GF2m -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DKECCAK1600_ASM -DRC4_ASM -DMD5_ASM -DVPAES_ASM -DGHASH_ASM -DECP_NISTZ256_ASM -DX25519_ASM -DPOLY1305_ASM -D_REENTRANT" "darwin64-x86_64-cc")
    generate_headers(${arch})

    set(PLs crypto/aes/asm/aesni-mb-x86_64.pl crypto/aes/asm/aesni-sha1-x86_64.pl crypto/aes/asm/aesni-sha256-x86_64.pl crypto/aes/asm/aesni-x86_64.pl crypto/aes/asm/vpaes-x86_64.pl crypto/bn/asm/rsaz-avx2.pl crypto/bn/asm/rsaz-x86_64.pl crypto/bn/asm/x86_64-gf2m.pl crypto/bn/asm/x86_64-mont.pl crypto/bn/asm/x86_64-mont5.pl crypto/camellia/asm/cmll-x86_64.pl crypto/chacha/asm/chacha-x86_64.pl crypto/ec/asm/ecp_nistz256-x86_64.pl crypto/ec/asm/x25519-x86_64.pl crypto/md5/asm/md5-x86_64.pl crypto/modes/asm/aesni-gcm-x86_64.pl crypto/modes/asm/ghash-x86_64.pl crypto/poly1305/asm/poly1305-x86_64.pl crypto/rc4/asm/rc4-md5-x86_64.pl crypto/rc4/asm/rc4-x86_64.pl crypto/sha/asm/keccak1600-x86_64.pl crypto/sha/asm/sha1-mb-x86_64.pl crypto/sha/asm/sha1-x86_64.pl crypto/sha/asm/sha256-mb-x86_64.pl crypto/sha/asm/sha512-x86_64.pl crypto/sha/asm/sha512-x86_64.pl crypto/whrlpool/asm/wp-x86_64.pl crypto/x86_64cpuid.pl engines/asm/e_padlock-x86_64.pl)
    set(ASMs crypto/aes/aesni-mb-x86_64.s crypto/aes/aesni-sha1-x86_64.s crypto/aes/aesni-sha256-x86_64.s crypto/aes/aesni-x86_64.s crypto/aes/vpaes-x86_64.s crypto/bn/rsaz-avx2.s crypto/bn/rsaz-x86_64.s crypto/bn/x86_64-gf2m.s crypto/bn/x86_64-mont.s crypto/bn/x86_64-mont5.s crypto/camellia/cmll-x86_64.s crypto/chacha/chacha-x86_64.s crypto/ec/ecp_nistz256-x86_64.s crypto/ec/x25519-x86_64.s crypto/md5/md5-x86_64.s crypto/modes/aesni-gcm-x86_64.s crypto/modes/ghash-x86_64.s crypto/poly1305/poly1305-x86_64.s crypto/rc4/rc4-md5-x86_64.s crypto/rc4/rc4-x86_64.s crypto/sha/keccak1600-x86_64.s crypto/sha/sha1-mb-x86_64.s crypto/sha/sha1-x86_64.s crypto/sha/sha256-mb-x86_64.s crypto/sha/sha256-x86_64.s crypto/sha/sha512-x86_64.s crypto/whrlpool/wp-x86_64.s crypto/x86_64cpuid.s engines/e_padlock-x86_64.s)
    pls_to_asms("${PLs}" "${ASMs}" macosx ${arch})

    add_library(ssl STATIC ${COMMON_ssl_SRCS})

    target_include_directories(ssl PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR})
    target_compile_definitions(ssl PRIVATE  MD5_ASM POLY1305_ASM X25519_ASM RC4_ASM OPENSSL_CPUID_OBJ OPENSSLDIR=${OPENSSLDIR} ECP_NISTZ256_ASM VPAES_ASM SHA256_ASM OPENSSL_BN_ASM_MONT5 _REENTRANT OPENSSL_IA32_SSE2 SHA1_ASM OPENSSL_PIC SHA512_ASM L_ENDIAN GHASH_ASM ENGINESDIR=${ENGINESDIR} KECCAK1600_ASM OPENSSL_BN_ASM_MONT OPENSSL_BN_ASM_GF2m)
    
    set(crypto_SRCS
        ${COMMON_crypto_SRCS}
        crypto/engine/eng_err.c crypto/x86_64cpuid.s crypto/whrlpool/wp-x86_64.s
        crypto/modes/aesni-gcm-x86_64.s crypto/aes/aesni-x86_64.s crypto/camellia/cmll-x86_64.s
        crypto/ec/x25519-x86_64.s crypto/bn/asm/x86_64-gcc.c crypto/engine/eng_init.c
        crypto/engine/eng_fat.c crypto/bn/rsaz_exp.c crypto/ec/ecp_nistz256.c
        crypto/sha/sha256-x86_64.s crypto/sha/sha1-mb-x86_64.s crypto/engine/tb_asnmth.c
        crypto/ec/ecp_nistz256-x86_64.s crypto/engine/eng_ctrl.c crypto/engine/tb_eckey.c
        crypto/engine/eng_table.c crypto/engine/eng_rdrand.c crypto/bn/x86_64-mont.s
        crypto/engine/eng_cnf.c crypto/bf/bf_enc.c crypto/sha/sha256-mb-x86_64.s
        crypto/aes/aesni-sha1-x86_64.s crypto/engine/tb_rand.c crypto/engine/eng_dyn.c
        crypto/chacha/chacha-x86_64.s crypto/engine/eng_list.c crypto/sha/sha1-x86_64.s
        crypto/engine/eng_lib.c crypto/engine/tb_cipher.c crypto/aes/aesni-mb-x86_64.s
        crypto/des/fcrypt_b.c crypto/engine/tb_pkmeth.c crypto/rc4/rc4-md5-x86_64.s
        crypto/rc4/rc4-x86_64.s crypto/des/des_enc.c crypto/modes/ghash-x86_64.s
        crypto/sha/keccak1600-x86_64.s crypto/md5/md5-x86_64.s crypto/bn/x86_64-mont5.s
        crypto/bn/rsaz-avx2.s crypto/engine/eng_all.c crypto/camellia/cmll_misc.c
        crypto/bn/rsaz-x86_64.s crypto/aes/aes_core.c crypto/engine/tb_digest.c
        crypto/aes/aesni-sha256-x86_64.s crypto/engine/tb_dsa.c crypto/bn/x86_64-gf2m.s
        crypto/poly1305/poly1305-x86_64.s crypto/aes/vpaes-x86_64.s crypto/engine/tb_dh.c
        crypto/engine/eng_pkey.c crypto/engine/eng_openssl.c crypto/sha/sha512-x86_64.s
        crypto/engine/tb_rsa.c
    )

    add_library(crypto STATIC ${crypto_SRCS})

    target_include_directories(crypto PRIVATE crypto/modes include ${CMAKE_CURRENT_SOURCE_DIR} crypto/ec/curve448/arch_32 crypto crypto/include crypto/ec/curve448)
    target_compile_definitions(crypto PRIVATE  MD5_ASM POLY1305_ASM X25519_ASM RC4_ASM OPENSSL_CPUID_OBJ OPENSSLDIR=${OPENSSLDIR} ECP_NISTZ256_ASM VPAES_ASM SHA256_ASM OPENSSL_BN_ASM_MONT5 _REENTRANT OPENSSL_IA32_SSE2 SHA1_ASM OPENSSL_PIC SHA512_ASM L_ENDIAN GHASH_ASM ENGINESDIR=${ENGINESDIR} KECCAK1600_ASM OPENSSL_BN_ASM_MONT OPENSSL_BN_ASM_GF2m)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-common -fPIC ")
    set_clang_unused()

elseif(CMAKE_OSX_SYSROOT MATCHES iPhoneOS)

    set(arch "ios-cross")
    message("Building ${arch}")

    find_program(PERL_EXECUTABLE perl)
    if(NOT PERL_EXECUTABLE)
        message(FATAL_ERROR("Perl not found"))
    endif(NOT PERL_EXECUTABLE)

    generate_configdata(${arch})
    generate_mkbuildinf("clang -arch arm64 -mios-version-min=7.0.0 -fno-common -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer//SDKs/iPhoneOS.sdk -DOPENSSL_PIC -D_REENTRANT" "ios64-cross")
    generate_headers(${arch})
    
    add_library(ssl STATIC ${COMMON_ssl_SRCS})

    target_include_directories(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
    target_compile_definitions(ssl PRIVATE  _REENTRANT OPENSSLDIR=${OPENSSLDIR} ENGINESDIR=${ENGINESDIR} OPENSSL_PIC)
    
    set(crypto_SRCS
        ${COMMON_crypto_SRCS}
        crypto/bf/bf_enc.c crypto/camellia/cmll_cbc.c crypto/sha/keccak1600.c
        crypto/mem_clr.c crypto/camellia/cmll_misc.c crypto/whrlpool/wp_block.c
        crypto/rc4/rc4_skey.c crypto/rc4/rc4_enc.c crypto/chacha/chacha_enc.c
        crypto/aes/aes_core.c crypto/bn/bn_asm.c crypto/des/fcrypt_b.c
        crypto/camellia/camellia.c crypto/des/des_enc.c
    )

    add_library(crypto STATIC ${crypto_SRCS})

    target_include_directories(crypto PRIVATE crypto/ec/curve448/arch_32 crypto/include include ${CMAKE_CURRENT_SOURCE_DIR} crypto/modes crypto/ec/curve448 crypto)
    target_compile_definitions(crypto PRIVATE  _REENTRANT OPENSSLDIR=${OPENSSLDIR} ENGINESDIR=${ENGINESDIR} OPENSSL_PIC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mios-version-min=7.0.0 -fno-common -fPIC ")
        
elseif(ANDROID)
    if(${ANDROID_ABI} STREQUAL "x86_64")

        set(arch "android-x86_64")
        message("Building ${arch}")
        
        file(COPY android/${arch}/opensslconf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/openssl/)
        file(COPY android/${arch}/bn_conf.h android/${arch}/dso_conf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/internal/)
        file(COPY android/${arch}/buildinf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/)
            
        add_library(ssl STATIC ${COMMON_ssl_SRCS})

        target_include_directories(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
        target_compile_definitions(ssl PRIVATE OPENSSL_USE_NODELETE OPENSSL_PIC ENGINESDIR=${ENGINESDIR} OPENSSLDIR=${OPENSSLDIR})
        
        set(crypto_SRCS
            ${COMMON_crypto_SRCS}
            ${crypto_SRC_android_ios}
        )

        add_library(crypto STATIC ${crypto_SRCS})

        target_include_directories(crypto PRIVATE crypto/modes crypto crypto/ec/curve448 crypto/include ${CMAKE_CURRENT_SOURCE_DIR} include crypto/ec/curve448/arch_32)
        target_compile_definitions(crypto PRIVATE OPENSSL_USE_NODELETE OPENSSL_PIC ENGINESDIR=${ENGINESDIR} OPENSSLDIR=${OPENSSLDIR})
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -pthread ")

    elseif(${ANDROID_ABI} STREQUAL "x86")

        set(arch "android-x86")
        message("Building ${arch}")

        file(COPY android/${arch}/opensslconf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/openssl/)
        file(COPY android/${arch}/bn_conf.h android/${arch}/dso_conf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/internal/)
        file(COPY android/${arch}/buildinf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/)

        add_library(ssl STATIC ${COMMON_ssl_SRCS})

        target_include_directories(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
        target_compile_definitions(ssl PRIVATE  ENGINESDIR=${ENGINESDIR} OPENSSL_PIC OPENSSLDIR=${OPENSSLDIR} OPENSSL_USE_NODELETE)
        
        set(crypto_SRCS
            ${COMMON_crypto_SRCS}
            ${crypto_SRC_android_ios}
        )

        add_library(crypto STATIC ${crypto_SRCS})

        target_include_directories(crypto PRIVATE crypto/ec/curve448/arch_32 crypto/modes ${CMAKE_CURRENT_SOURCE_DIR} include crypto/ec/curve448 crypto crypto/include)
        target_compile_definitions(crypto PRIVATE  ENGINESDIR=${ENGINESDIR} OPENSSL_PIC OPENSSLDIR=${OPENSSLDIR} OPENSSL_USE_NODELETE)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fomit-frame-pointer -pthread  -fPIC")
        
    elseif(${ANDROID_ABI} STREQUAL "armeabi-v7a")

        set(arch "android-arm")
        message("Building ${arch}")
        
        file(COPY android/${arch}/opensslconf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/openssl/)
        file(COPY android/${arch}/bn_conf.h android/${arch}/dso_conf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/internal/)
        file(COPY android/${arch}/buildinf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/)
            
        add_library(ssl STATIC ${COMMON_ssl_SRCS})

        target_include_directories(ssl PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR})
        target_compile_definitions(ssl PRIVATE OPENSSL_PIC OPENSSLDIR=${OPENSSLDIR} OPENSSL_USE_NODELETE ENGINESDIR=${ENGINESDIR})
        
        set(crypto_SRCS
            ${COMMON_crypto_SRCS}
            ${crypto_SRC_android_ios}
        )

        add_library(crypto STATIC ${crypto_SRCS})

        target_include_directories(crypto PRIVATE crypto/include crypto crypto/modes ${CMAKE_CURRENT_SOURCE_DIR} crypto/ec/curve448/arch_32 crypto/ec/curve448 include)
        target_compile_definitions(crypto PRIVATE OPENSSL_PIC OPENSSLDIR=${OPENSSLDIR} OPENSSL_USE_NODELETE ENGINESDIR=${ENGINESDIR})
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -pthread -fPIC")

    elseif(${ANDROID_ABI} STREQUAL "arm64-v8a")

        set(arch "android-arm64")
        message("Building ${arch}")
        
        file(COPY android/${arch}/opensslconf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/openssl/)
        file(COPY android/${arch}/bn_conf.h android/${arch}/dso_conf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/internal/)
        file(COPY android/${arch}/buildinf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/)
            
        add_library(ssl STATIC ${COMMON_ssl_SRCS})

        target_include_directories(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
        target_compile_definitions(ssl PRIVATE  OPENSSL_PIC ENGINESDIR=${ENGINESDIR} OPENSSL_USE_NODELETE OPENSSLDIR=${OPENSSLDIR})
        
        set(crypto_SRCS
            ${COMMON_crypto_SRCS}
            ${crypto_SRC_android_ios}
        )

        add_library(crypto STATIC ${crypto_SRCS})

        target_include_directories(crypto PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} crypto/ec/curve448/arch_32 crypto/include crypto/modes crypto crypto/ec/curve448 include)
        target_compile_definitions(crypto PRIVATE  OPENSSL_PIC ENGINESDIR=${ENGINESDIR} OPENSSL_USE_NODELETE OPENSSLDIR=${OPENSSLDIR})
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC  -pthread")

    endif() #arm64
elseif(WIN32)

    message(FATAL_ERROR("Windows is not currently supported"))

elseif(UNIX)

    set(arch "linux-x86_64-clang")
    message("Building ${arch}")

    find_program(PERL_EXECUTABLE perl)
    if(NOT PERL_EXECUTABLE)
        message(FATAL_ERROR("Perl not found"))
    endif(NOT PERL_EXECUTABLE)

    generate_configdata(${arch})
    generate_mkbuildinf("clang -pthread -m64 -Wa,--noexecstack -DOPENSSL_USE_NODELETE -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_CPUID_OBJ -DOPENSSL_IA32_SSE2 -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_MONT5 -DOPENSSL_BN_ASM_GF2m -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DKECCAK1600_ASM -DRC4_ASM -DMD5_ASM -DVPAES_ASM -DGHASH_ASM -DECP_NISTZ256_ASM -DX25519_ASM -DPOLY1305_ASM" "linux-x86_64-clang")
    generate_headers(${arch})
    
    set(PLs crypto/aes/asm/aesni-mb-x86_64.pl crypto/aes/asm/aesni-sha1-x86_64.pl crypto/aes/asm/aesni-sha256-x86_64.pl crypto/aes/asm/aesni-x86_64.pl crypto/aes/asm/vpaes-x86_64.pl crypto/bn/asm/rsaz-avx2.pl crypto/bn/asm/rsaz-x86_64.pl crypto/bn/asm/x86_64-gf2m.pl crypto/bn/asm/x86_64-mont.pl crypto/bn/asm/x86_64-mont5.pl crypto/camellia/asm/cmll-x86_64.pl crypto/chacha/asm/chacha-x86_64.pl crypto/ec/asm/ecp_nistz256-x86_64.pl crypto/ec/asm/x25519-x86_64.pl crypto/md5/asm/md5-x86_64.pl crypto/modes/asm/aesni-gcm-x86_64.pl crypto/modes/asm/ghash-x86_64.pl crypto/poly1305/asm/poly1305-x86_64.pl crypto/rc4/asm/rc4-md5-x86_64.pl crypto/rc4/asm/rc4-x86_64.pl crypto/sha/asm/keccak1600-x86_64.pl crypto/sha/asm/sha1-mb-x86_64.pl crypto/sha/asm/sha1-x86_64.pl crypto/sha/asm/sha256-mb-x86_64.pl crypto/sha/asm/sha512-x86_64.pl crypto/sha/asm/sha512-x86_64.pl crypto/whrlpool/asm/wp-x86_64.pl crypto/x86_64cpuid.pl engines/asm/e_padlock-x86_64.pl)
    set(ASMs crypto/aes/aesni-mb-x86_64.s crypto/aes/aesni-sha1-x86_64.s crypto/aes/aesni-sha256-x86_64.s crypto/aes/aesni-x86_64.s crypto/aes/vpaes-x86_64.s crypto/bn/rsaz-avx2.s crypto/bn/rsaz-x86_64.s crypto/bn/x86_64-gf2m.s crypto/bn/x86_64-mont.s crypto/bn/x86_64-mont5.s crypto/camellia/cmll-x86_64.s crypto/chacha/chacha-x86_64.s crypto/ec/ecp_nistz256-x86_64.s crypto/ec/x25519-x86_64.s crypto/md5/md5-x86_64.s crypto/modes/aesni-gcm-x86_64.s crypto/modes/ghash-x86_64.s crypto/poly1305/poly1305-x86_64.s crypto/rc4/rc4-md5-x86_64.s crypto/rc4/rc4-x86_64.s crypto/sha/keccak1600-x86_64.s crypto/sha/sha1-mb-x86_64.s crypto/sha/sha1-x86_64.s crypto/sha/sha256-mb-x86_64.s crypto/sha/sha256-x86_64.s crypto/sha/sha512-x86_64.s crypto/whrlpool/wp-x86_64.s crypto/x86_64cpuid.s engines/e_padlock-x86_64.s)
    pls_to_asms("${PLs}" "${ASMs}" elf ${arch})
        
    add_library(ssl STATIC ${COMMON_ssl_SRCS})

    target_include_directories(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
    target_compile_definitions(ssl PRIVATE  ECP_NISTZ256_ASM SHA1_ASM POLY1305_ASM GHASH_ASM ENGINESDIR=${ENGINESDIR} OPENSSL_BN_ASM_MONT5 VPAES_ASM KECCAK1600_ASM L_ENDIAN X25519_ASM OPENSSLDIR=${OPENSSLDIR} RC4_ASM MD5_ASM SHA256_ASM OPENSSL_IA32_SSE2 OPENSSL_PIC OPENSSL_BN_ASM_MONT OPENSSL_BN_ASM_GF2m SHA512_ASM OPENSSL_CPUID_OBJ OPENSSL_USE_NODELETE)
    
    set(crypto_SRCS
        ${COMMON_crypto_SRCS}
        crypto/engine/tb_pkmeth.c crypto/sha/sha512-x86_64.s crypto/engine/eng_table.c
        crypto/ec/ecp_nistz256.c crypto/bn/x86_64-mont.s crypto/engine/tb_dh.c
        crypto/rc4/rc4-x86_64.s crypto/engine/eng_ctrl.c crypto/camellia/cmll_misc.c
        crypto/sha/sha256-x86_64.s crypto/md5/md5-x86_64.s crypto/modes/ghash-x86_64.s
        crypto/engine/eng_lib.c crypto/engine/tb_rand.c crypto/x86_64cpuid.s
        crypto/bn/x86_64-mont5.s crypto/engine/tb_eckey.c crypto/engine/tb_digest.c
        crypto/sha/sha1-x86_64.s crypto/engine/tb_asnmth.c crypto/poly1305/poly1305-x86_64.s
        crypto/ec/ecp_nistz256-x86_64.s crypto/modes/aesni-gcm-x86_64.s crypto/engine/eng_fat.c
        crypto/sha/sha1-mb-x86_64.s crypto/bn/rsaz-x86_64.s crypto/rc4/rc4-md5-x86_64.s
        crypto/aes/aesni-sha1-x86_64.s crypto/aes/aes_core.c crypto/engine/tb_dsa.c
        crypto/engine/eng_all.c crypto/bn/rsaz_exp.c crypto/whrlpool/wp-x86_64.s
        crypto/engine/eng_rdrand.c crypto/bn/x86_64-gf2m.s crypto/camellia/cmll-x86_64.s
        crypto/engine/eng_list.c crypto/bf/bf_enc.c crypto/bn/rsaz-avx2.s
        crypto/engine/eng_cnf.c crypto/engine/tb_rsa.c crypto/des/fcrypt_b.c
        crypto/aes/aesni-mb-x86_64.s crypto/aes/vpaes-x86_64.s crypto/aes/aesni-sha256-x86_64.s
        crypto/des/des_enc.c crypto/sha/sha256-mb-x86_64.s crypto/ec/x25519-x86_64.s
        crypto/engine/eng_err.c crypto/engine/eng_init.c crypto/engine/eng_dyn.c
        crypto/engine/eng_pkey.c crypto/engine/tb_cipher.c crypto/aes/aesni-x86_64.s
        crypto/bn/asm/x86_64-gcc.c crypto/sha/keccak1600-x86_64.s crypto/chacha/chacha-x86_64.s
        crypto/engine/eng_openssl.c
    )

    add_library(crypto STATIC ${crypto_SRCS})

    target_include_directories(crypto PRIVATE crypto/include include ${CMAKE_CURRENT_SOURCE_DIR} crypto crypto/ec/curve448 crypto/modes crypto/ec/curve448/arch_32)
    target_compile_definitions(crypto PRIVATE  ECP_NISTZ256_ASM SHA1_ASM POLY1305_ASM GHASH_ASM ENGINESDIR=${ENGINESDIR} OPENSSL_BN_ASM_MONT5 VPAES_ASM KECCAK1600_ASM L_ENDIAN X25519_ASM OPENSSLDIR=${OPENSSLDIR} RC4_ASM MD5_ASM SHA256_ASM OPENSSL_IA32_SSE2 OPENSSL_PIC OPENSSL_BN_ASM_MONT OPENSSL_BN_ASM_GF2m SHA512_ASM OPENSSL_CPUID_OBJ OPENSSL_USE_NODELETE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -m64 -Wa,--noexecstack -fPIC")
    set_clang_unused()
endif()

