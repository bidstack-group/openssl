cmake_minimum_required(VERSION 3.14)
project(open_ssl C ASM)


SET(COMMON_ssl_SRCS
    ssl/statem/statem_clnt.c ssl/t1_trce.c
    ssl/record/rec_layer_d1.c ssl/ssl_stat.c
    ssl/d1_lib.c ssl/statem/statem.c
    ssl/ssl_rsa.c ssl/record/ssl3_record.c
    ssl/t1_enc.c ssl/ssl_asn1.c
    ssl/statem/extensions_cust.c ssl/ssl_utst.c
    ssl/ssl_cert.c ssl/tls_srp.c
    ssl/ssl_sess.c ssl/bio_ssl.c
    ssl/ssl_conf.c ssl/d1_msg.c
    ssl/statem/extensions.c ssl/ssl_init.c
    ssl/statem/extensions_clnt.c ssl/statem/statem_srvr.c
    ssl/record/ssl3_buffer.c ssl/record/rec_layer_s3.c
    ssl/ssl_lib.c ssl/s3_lib.c
    ssl/ssl_txt.c ssl/statem/statem_dtls.c
    ssl/ssl_mcnf.c ssl/methods.c
    ssl/statem/extensions_srvr.c ssl/record/ssl3_record_tls13.c
    ssl/packet.c ssl/t1_lib.c
    ssl/ssl_ciph.c ssl/d1_srtp.c
    ssl/statem/statem_lib.c ssl/ssl_err.c
    ssl/s3_cbc.c ssl/s3_enc.c
    ssl/record/dtls1_bitmap.c ssl/s3_msg.c
    ssl/tls13_enc.c ssl/pqueue.c
    )
SET(COMMON_crypto_SRCS
    crypto/bio/b_addr.c crypto/ui/ui_util.c crypto/bn/bn_add.c crypto/x509v3/pcy_data.c crypto/des/fcrypt.c crypto/ts/ts_lib.c
    crypto/evp/e_bf.c crypto/pkcs12/p12_kiss.c crypto/rand/randfile.c crypto/dsa/dsa_err.c crypto/aes/aes_ecb.c crypto/md4/md4_dgst.c
    crypto/ec/curve448/scalar.c crypto/pem/pvkfmt.c crypto/rsa/rsa_ameth.c crypto/bn/bn_ctx.c crypto/evp/m_md4.c crypto/evp/evp_enc.c
    crypto/evp/names.c crypto/asn1/asn1_par.c crypto/x509v3/v3_genn.c crypto/evp/m_mdc2.c crypto/bn/bn_err.c crypto/pkcs12/p12_attr.c
    crypto/bn/bn_kron.c crypto/dh/dh_prn.c crypto/pem/pem_err.c crypto/evp/pbe_scrypt.c crypto/x509/x509_vpm.c crypto/asn1/a_verify.c
    crypto/dsa/dsa_lib.c crypto/x509v3/pcy_cache.c crypto/x509v3/v3_purp.c crypto/o_time.c crypto/asn1/d2i_pr.c crypto/evp/e_des.c
    crypto/asn1/a_bitstr.c crypto/ec/curve448/curve448_tables.c crypto/modes/ofb128.c crypto/x509/t_crl.c crypto/ec/ec_key.c crypto/pkcs12/p12_init.c
    crypto/x509v3/v3_addr.c crypto/idea/i_skey.c crypto/bn/bn_mpi.c crypto/evp/c_alld.c crypto/store/store_register.c crypto/rsa/rsa_oaep.c
    crypto/x509/x509_r2x.c crypto/asn1/asn_moid.c crypto/asn1/tasn_new.c crypto/rsa/rsa_mp.c crypto/pkcs12/p12_key.c crypto/ec/ecp_nistp256.c
    crypto/asn1/a_sign.c crypto/seed/seed_ofb.c crypto/evp/e_aes.c crypto/async/async_wait.c crypto/asn1/i2d_pr.c crypto/x509v3/pcy_tree.c
    crypto/asn1/bio_ndef.c crypto/asn1/a_object.c crypto/x509/x_attrib.c crypto/ripemd/rmd_one.c crypto/bn/bn_depr.c crypto/pem/pem_lib.c
    crypto/ct/ct_log.c crypto/asn1/p5_pbev2.c crypto/ct/ct_err.c crypto/rc2/rc2ofb64.c crypto/x509v3/v3_skey.c crypto/async/arch/async_posix.c
    crypto/rsa/rsa_meth.c crypto/rand/drbg_lib.c crypto/ocsp/ocsp_vfy.c crypto/rand/rand_unix.c crypto/x509/t_x509.c crypto/x509/x509_d2.c
    crypto/evp/p_enc.c crypto/ct/ct_policy.c crypto/x509/x509_v3.c crypto/evp/e_sm4.c crypto/pkcs12/p12_utl.c crypto/conf/conf_err.c
    crypto/dsa/dsa_prn.c crypto/pkcs12/p12_sbag.c crypto/bn/bn_recp.c crypto/asn1/a_mbstr.c crypto/modes/ccm128.c crypto/evp/bio_enc.c
    crypto/x509v3/v3_enum.c crypto/ec/ecp_oct.c crypto/cast/c_enc.c crypto/dso/dso_win32.c crypto/asn1/p5_scrypt.c crypto/siphash/siphash.c
    crypto/x509v3/v3_conf.c crypto/rsa/rsa_pss.c crypto/pkcs7/pkcs7err.c crypto/rsa/rsa_pmeth.c crypto/x509/x509_trs.c crypto/rsa/rsa_ossl.c
    crypto/rand/rand_err.c crypto/x509v3/v3_bcons.c crypto/pem/pem_pk8.c crypto/x509v3/pcy_lib.c crypto/sm3/m_sm3.c crypto/asn1/tasn_scn.c
    crypto/ec/ec2_oct.c crypto/bn/bn_x931p.c crypto/evp/p_lib.c crypto/ct/ct_sct_ctx.c crypto/asn1/t_pkey.c crypto/ec/ec_check.c
    crypto/seed/seed_cfb.c crypto/x509/x_pubkey.c crypto/bn/bn_dh.c crypto/x509/by_dir.c crypto/x509/t_req.c crypto/aes/aes_wrap.c
    crypto/getenv.c crypto/kdf/scrypt.c crypto/evp/bio_md.c crypto/evp/c_allc.c crypto/x509v3/v3_ncons.c crypto/asn1/tasn_prn.c
    crypto/x509/x509_lu.c crypto/bio/bss_acpt.c crypto/ec/ecdh_kdf.c crypto/whrlpool/wp_dgst.c crypto/modes/ctr128.c crypto/bn/bn_word.c
    crypto/rsa/rsa_x931.c crypto/x509/x509type.c crypto/dh/dh_meth.c crypto/des/cfb_enc.c crypto/bn/bn_gf2m.c crypto/objects/obj_lib.c
    crypto/x509/x509name.c crypto/ec/ec_kmeth.c crypto/o_dir.c crypto/asn1/tasn_utl.c crypto/evp/m_md5_sha1.c crypto/asn1/a_strex.c
    crypto/evp/evp_lib.c crypto/asn1/a_time.c crypto/comp/comp_lib.c crypto/sha/sha1dgst.c crypto/rand/rand_win.c crypto/ec/curve448/arch_32/f_impl.c
    crypto/evp/p_verify.c crypto/kdf/kdf_err.c crypto/asn1/asn1_gen.c crypto/ct/ct_sct.c crypto/cast/c_cfb64.c crypto/bn/bn_blind.c
    crypto/ec/ec_ameth.c crypto/x509/x509_set.c crypto/cms/cms_env.c crypto/ui/ui_lib.c crypto/asn1/i2d_pu.c crypto/modes/cfb128.c
    crypto/store/loader_file.c crypto/x509v3/pcy_node.c crypto/x509v3/v3_pcons.c crypto/dh/dh_rfc7919.c crypto/ts/ts_rsp_verify.c crypto/bn/bn_exp2.c
    crypto/x509v3/v3_akeya.c crypto/ec/ecp_nistputil.c crypto/asn1/a_print.c crypto/aes/aes_ige.c crypto/hmac/hm_ameth.c crypto/x509v3/v3_tlsf.c
    crypto/ebcdic.c crypto/dsa/dsa_ossl.c crypto/ts/ts_conf.c crypto/ec/ecx_meth.c crypto/seed/seed_cbc.c crypto/evp/e_chacha20_poly1305.c
    crypto/dh/dh_lib.c crypto/cms/cms_kari.c crypto/rand/drbg_ctr.c crypto/o_fips.c crypto/x509v3/v3err.c crypto/cmac/cmac.c
    crypto/ui/ui_openssl.c crypto/pkcs7/pk7_lib.c crypto/blake2/blake2b.c crypto/x509/x509spki.c crypto/sm2/sm2_err.c crypto/evp/m_sha1.c
    crypto/ripemd/rmd_dgst.c crypto/asn1/bio_asn1.c crypto/dh/dh_ameth.c crypto/sha/sha1_one.c crypto/dso/dso_vms.c crypto/objects/obj_xref.c
    crypto/asn1/a_i2d_fp.c crypto/asn1/asn1_lib.c crypto/ec/ec_err.c crypto/blake2/m_blake2s.c crypto/aes/aes_cfb.c crypto/ec/ecdsa_ossl.c
    crypto/md5/md5_dgst.c crypto/pkcs12/p12_npas.c crypto/evp/e_rc4.c crypto/txt_db/txt_db.c crypto/des/xcbc_enc.c crypto/bn/bn_gcd.c
    crypto/dh/dh_key.c crypto/cryptlib.c crypto/x509/x_x509a.c crypto/bio/b_sock.c crypto/conf/conf_lib.c crypto/x509v3/v3_pcia.c
    crypto/x509/x509_ext.c crypto/idea/i_cbc.c crypto/asn1/tasn_dec.c crypto/x509/x509_meth.c crypto/pem/pem_xaux.c crypto/bn/bn_sqr.c
    crypto/des/cfb64ede.c crypto/evp/m_null.c crypto/des/ofb_enc.c crypto/asn1/x_long.c crypto/asn1/x_algor.c crypto/x509/x_crl.c
    crypto/bf/bf_skey.c crypto/evp/p_sign.c crypto/asn1/asn_pack.c crypto/evp/bio_b64.c crypto/threads_pthread.c crypto/evp/p5_crpt.c
    crypto/objects/obj_dat.c crypto/rsa/rsa_none.c crypto/o_fopen.c crypto/pem/pem_pkey.c crypto/asn1/tasn_fre.c crypto/bn/bn_const.c
    crypto/asn1/x_sig.c crypto/evp/e_rc4_hmac_md5.c crypto/hmac/hmac.c crypto/srp/srp_lib.c crypto/siphash/siphash_pmeth.c crypto/asn1/tasn_typ.c
    crypto/bio/bio_cb.c crypto/ec/ec2_smpl.c crypto/poly1305/poly1305_pmeth.c crypto/ct/ct_b64.c crypto/cms/cms_cd.c crypto/uid.c
    crypto/cms/cms_enc.c crypto/ec/ec_pmeth.c crypto/asn1/x_val.c crypto/asn1/n_pkey.c crypto/evp/e_rc5.c crypto/sm2/sm2_sign.c
    crypto/ec/ec_mult.c crypto/evp/e_camellia.c crypto/asn1/x_int64.c crypto/camellia/cmll_ofb.c crypto/conf/conf_sap.c crypto/ec/curve448/eddsa.c
    crypto/bio/b_sock2.c crypto/kdf/hkdf.c crypto/evp/p_seal.c crypto/init.c crypto/ec/eck_prn.c crypto/ts/ts_rsp_sign.c
    crypto/x509/x_all.c crypto/camellia/cmll_cfb.c crypto/asn1/f_int.c crypto/ec/ecp_mont.c crypto/ocsp/ocsp_cl.c crypto/bn/bn_rand.c
    crypto/async/async.c crypto/x509/x_x509.c crypto/rc2/rc2_cbc.c crypto/conf/conf_mall.c crypto/rsa/rsa_asn1.c crypto/rsa/rsa_crpt.c
    crypto/x509v3/v3_asid.c crypto/evp/e_xcbc_d.c crypto/cpt_err.c crypto/poly1305/poly1305.c crypto/threads_none.c crypto/x509/x509cset.c
    crypto/pkcs12/p12_p8d.c crypto/dsa/dsa_asn1.c crypto/camellia/cmll_misc.c crypto/bio/bf_buff.c crypto/x509v3/v3_ia5.c crypto/bn/bn_prime.c
    crypto/bn/bn_nist.c crypto/bn/bn_intern.c crypto/srp/srp_vfy.c crypto/bio/bss_conn.c crypto/asn1/x_info.c crypto/x509/by_file.c
    crypto/modes/cbc128.c crypto/ts/ts_asn1.c crypto/rc2/rc2_skey.c crypto/rand/rand_lib.c crypto/bn/bn_mul.c crypto/cms/cms_io.c
    crypto/asn1/a_gentm.c crypto/bio/bss_log.c crypto/dh/dh_pmeth.c crypto/ocsp/ocsp_srv.c crypto/evp/e_null.c crypto/asn1/asn1_err.c
    crypto/seed/seed.c crypto/cms/cms_err.c crypto/aes/aes_misc.c crypto/x509/x_name.c crypto/store/store_strings.c crypto/dso/dso_dl.c
    crypto/ex_data.c crypto/asn1/tasn_enc.c crypto/x509v3/v3_admis.c crypto/cmac/cm_ameth.c crypto/evp/e_old.c crypto/lhash/lh_stats.c
    crypto/rc2/rc2_ecb.c crypto/ts/ts_verify_ctx.c crypto/evp/e_rc2.c crypto/ct/ct_x509v3.c crypto/des/cfb64enc.c crypto/cms/cms_asn1.c
    crypto/pkcs7/bio_pk7.c crypto/dsa/dsa_key.c crypto/sha/sha512.c crypto/bio/bss_dgram.c crypto/asn1/f_string.c crypto/modes/xts128.c
    crypto/err/err.c crypto/evp/evp_cnf.c crypto/evp/cmeth_lib.c crypto/kdf/tls1_prf.c crypto/ec/ecdh_ossl.c crypto/buffer/buf_err.c
    crypto/dsa/dsa_vrf.c crypto/pkcs12/p12_decr.c crypto/store/store_lib.c crypto/rsa/rsa_lib.c crypto/bf/bf_ofb64.c crypto/pkcs12/pk12err.c
    crypto/evp/e_aes_cbc_hmac_sha256.c crypto/evp/e_seed.c crypto/mem_dbg.c crypto/dso/dso_dlfcn.c crypto/asn1/x_pkey.c crypto/bio/bio_meth.c
    crypto/dso/dso_lib.c crypto/seed/seed_ecb.c crypto/conf/conf_api.c crypto/bio/bss_null.c crypto/conf/conf_def.c crypto/comp/c_zlib.c
    crypto/rsa/rsa_chk.c crypto/evp/bio_ok.c crypto/ec/ec_curve.c crypto/sm4/sm4.c crypto/cms/cms_dd.c crypto/ec/ec_lib.c
    crypto/evp/pmeth_lib.c crypto/sm3/sm3.c crypto/x509/x_exten.c crypto/mdc2/mdc2dgst.c crypto/des/ofb64enc.c crypto/ct/ct_vfy.c
    crypto/x509v3/v3_prn.c crypto/asn1/a_digest.c crypto/bn/bn_shift.c crypto/des/fcrypt_b.c crypto/ts/ts_err.c crypto/camellia/cmll_ecb.c
    crypto/dsa/dsa_meth.c crypto/rc2/rc2cfb64.c crypto/cms/cms_ess.c crypto/x509/x509_err.c crypto/pem/pem_sign.c crypto/ec/ecp_nist.c
    crypto/mem.c crypto/idea/i_cfb64.c crypto/mdc2/mdc2_one.c crypto/cmac/cm_pmeth.c crypto/pem/pem_x509.c crypto/bio/bss_mem.c
    crypto/objects/o_names.c crypto/rsa/rsa_sign.c crypto/x509/x509rset.c crypto/x509v3/v3_akey.c crypto/pkcs7/pk7_attr.c crypto/x509v3/pcy_map.c
    crypto/conf/conf_ssl.c crypto/rsa/rsa_x931g.c crypto/x509/x509_req.c crypto/pkcs12/p12_add.c crypto/cversion.c crypto/err/err_prn.c
    crypto/aes/aes_ofb.c crypto/asn1/asn_mstbl.c crypto/des/str2key.c crypto/rsa/rsa_pk1.c crypto/ec/ecdsa_vrf.c crypto/ctype.c
    crypto/ec/ec_print.c crypto/x509v3/v3_lib.c crypto/async/arch/async_win.c crypto/x509/x509_vfy.c crypto/hmac/hm_pmeth.c crypto/pem/pem_info.c
    crypto/siphash/siphash_ameth.c crypto/asn1/asn_mime.c crypto/stack/stack.c crypto/x509/x509_att.c crypto/threads_win.c crypto/asn1/a_dup.c
    crypto/asn1/a_d2i_fp.c crypto/asn1/a_strnid.c crypto/ec/curve448/f_generic.c crypto/comp/comp_err.c crypto/ec/ec_oct.c crypto/des/qud_cksm.c
    crypto/ocsp/ocsp_ht.c crypto/dso/dso_openssl.c crypto/x509v3/v3_bitst.c crypto/ui/ui_err.c crypto/bio/bf_null.c crypto/ui/ui_null.c
    crypto/evp/encode.c crypto/x509v3/v3_utl.c crypto/modes/wrap128.c crypto/store/store_err.c crypto/md5/md5_one.c crypto/ec/ecp_smpl.c
    crypto/md4/md4_one.c crypto/objects/obj_err.c crypto/pkcs7/pk7_doit.c crypto/asn1/p8_pkey.c crypto/asn1/t_bitst.c crypto/x509/x509_obj.c
    crypto/dh/dh_kdf.c crypto/ct/ct_oct.c crypto/x509v3/v3_alt.c crypto/rsa/rsa_saos.c crypto/evp/p_dec.c crypto/ts/ts_req_print.c
    crypto/modes/gcm128.c crypto/mem_sec.c crypto/pkcs7/pk7_smime.c crypto/rand/rand_vms.c crypto/x509v3/v3_cpols.c crypto/bn/bn_mont.c
    crypto/sm2/sm2_pmeth.c crypto/evp/e_idea.c crypto/sm2/sm2_crypt.c crypto/rand/rand_egd.c crypto/pkcs12/p12_mutl.c crypto/bio/bio_lib.c
    crypto/evp/m_md5.c crypto/evp/m_ripemd.c crypto/dsa/dsa_sign.c crypto/aes/aes_core.c crypto/asn1/t_spki.c crypto/bn/bn_exp.c
    crypto/rsa/rsa_err.c crypto/evp/m_md2.c crypto/rsa/rsa_prn.c crypto/ec/ec_cvt.c crypto/dsa/dsa_gen.c crypto/x509v3/v3_sxnet.c
    crypto/asn1/a_int.c crypto/ocsp/ocsp_asn.c crypto/des/ecb3_enc.c crypto/evp/p_open.c crypto/rsa/rsa_depr.c crypto/des/des_enc.c
    crypto/ec/ec_asn1.c crypto/des/rand_key.c crypto/asn1/d2i_pu.c crypto/idea/i_ofb64.c crypto/o_init.c crypto/ocsp/ocsp_err.c
    crypto/conf/conf_mod.c crypto/bio/bss_bio.c crypto/bio/bf_nbio.c crypto/dh/dh_err.c crypto/bio/bio_err.c crypto/evp/m_sigver.c
    crypto/blake2/m_blake2b.c crypto/asn1/p5_pbe.c crypto/modes/ocb128.c crypto/evp/e_aes_cbc_hmac_sha1.c crypto/des/ecb_enc.c crypto/evp/m_sha3.c
    crypto/asn1/a_octet.c crypto/pkcs7/pk7_mime.c crypto/asn1/x_spki.c crypto/ec/ecp_nistp521.c crypto/bio/bss_file.c crypto/cast/c_ofb64.c
    crypto/evp/m_wp.c crypto/dh/dh_gen.c crypto/evp/evp_err.c crypto/blake2/blake2s.c crypto/rsa/rsa_ssl.c crypto/x509v3/v3_pmaps.c
    crypto/x509v3/v3_crld.c crypto/x509v3/v3_info.c crypto/evp/p5_crpt2.c crypto/bio/b_print.c crypto/ocsp/ocsp_lib.c crypto/bf/bf_enc.c
    crypto/des/set_key.c crypto/ec/ecdsa_sign.c crypto/dh/dh_check.c crypto/x509v3/v3_int.c crypto/x509v3/v3_pci.c crypto/cast/c_ecb.c
    crypto/pkcs12/p12_asn.c crypto/x509/x509_txt.c crypto/evp/pmeth_gn.c crypto/asn1/evp_asn1.c crypto/aria/aria.c crypto/cms/cms_lib.c
    crypto/asn1/nsseq.c crypto/aes/aes_cbc.c crypto/ocsp/ocsp_prn.c crypto/evp/pmeth_fn.c crypto/ec/curve25519.c crypto/ts/ts_rsp_print.c
    crypto/cms/cms_smime.c crypto/ec/ecp_nistp224.c crypto/asn1/x_bignum.c crypto/des/cbc_enc.c crypto/bio/b_dump.c crypto/evp/e_cast.c
    crypto/bn/bn_mod.c crypto/dh/dh_rfc5114.c crypto/pem/pem_all.c crypto/asn1/ameth_lib.c crypto/pkcs7/pk7_asn1.c crypto/asn1/asn1_item_list.c
    crypto/asn1/a_type.c crypto/x509/x509_def.c crypto/store/store_init.c crypto/pkcs12/p12_crt.c crypto/asn1/a_utf8.c crypto/idea/i_ecb.c
    crypto/poly1305/poly1305_ameth.c crypto/bn/bn_sqrt.c crypto/camellia/cmll_ctr.c crypto/dh/dh_depr.c crypto/evp/e_des3.c crypto/buffer/buffer.c
    crypto/async/async_err.c crypto/err/err_all.c crypto/bn/bn_div.c crypto/async/arch/async_null.c crypto/bn/bn_srp.c crypto/x509/x_req.c
    crypto/evp/evp_key.c crypto/cms/cms_att.c crypto/evp/evp_pkey.c crypto/o_str.c crypto/des/ofb64ede.c crypto/dsa/dsa_depr.c
    crypto/x509v3/v3_extku.c crypto/rsa/rsa_gen.c crypto/ocsp/ocsp_ext.c crypto/ec/curve448/curve448.c crypto/evp/digest.c crypto/pkcs12/p12_crpt.c
    crypto/dsa/dsa_ameth.c crypto/cms/cms_pwri.c crypto/modes/cts128.c crypto/dso/dso_err.c crypto/x509v3/v3_pku.c crypto/asn1/a_utctm.c
    crypto/des/cbc_cksm.c crypto/bf/bf_ecb.c crypto/dh/dh_asn1.c crypto/ct/ct_prn.c crypto/cms/cms_sd.c crypto/dsa/dsa_pmeth.c
    crypto/evp/e_aria.c crypto/ts/ts_rsp_utils.c crypto/bf/bf_cfb64.c crypto/bn/bn_print.c crypto/x509/x509_cmp.c crypto/bio/bss_fd.c
    crypto/evp/evp_pbe.c crypto/bio/bss_sock.c crypto/cast/c_skey.c crypto/ts/ts_req_utils.c crypto/sha/sha256.c crypto/pkcs12/p12_p8e.c
    crypto/bio/bf_lbuf.c crypto/ocsp/v3_ocsp.c crypto/des/pcbc_enc.c crypto/bn/bn_lib.c crypto/pem/pem_oth.c crypto/lhash/lhash.c
    )


if(CMAKE_OSX_SYSROOT MATCHES iPhoneSimulator)
    
        set(arch "iossimulator-xcrun")
        find_program(PERL_EXECUTABLE perl)
        if(NOT PERL_EXECUTABLE)
            message(FATAL_ERROR("Perl not found"))
        endif(NOT PERL_EXECUTABLE)

        message("Configuring configdata.pm for \"${arch}\"")
        EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} Configure ${arch} no-asm
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                OUTPUT_VARIABLE TEMP
                ERROR_VARIABLE ERROR
        )
        if(ERROR)
            MESSAGE(FATAL_ERROR("Error while configuring: ${ERROR}"))
        endif(ERROR)

        EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} util/mkbuildinf.pl "clang -fPIC -arch arm64 -mios-version-min=7.0.0 -fno-common -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer//SDKs/iPhoneOS.sdk -O3 -DOPENSSL_PIC -D_REENTRANT -DNDEBUG" "ios64-cross"
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_FILE crypto/buildinf.h
            ERROR_VARIABLE ERROR)
        if(ERROR)
            MESSAGE(FATAL_ERROR("Error while generating mkbuildinf: ${ERROR}"))
        endif(ERROR)

        foreach(el crypto/include/internal/bn_conf.h;crypto/include/internal/dso_conf.h;include/openssl/opensslconf.h)
            MESSAGE("Generating ${el}")
            EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE}
                "-I${CMAKE_CURRENT_LIST_DIR}" -Mconfigdata "util/dofile.pl" "-oMakefile" ${el}.in
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                OUTPUT_FILE ${el}
                ERROR_VARIABLE error)
            if(error)
                message(FATAL_ERROR("Error while generating: ${error}"))
            endif(error)
        endforeach()

        set(PLs util/mkbuildinf.pl)
        set(ASMs /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer//SDKs/iPhoneOS.s)
        list(LENGTH PLs _len)
        math(EXPR len "${_len}-1")
        foreach(idx RANGE ${len})

            list(GET PLs ${idx} pl)
            list(GET ASMs ${idx} asm)
            MESSAGE("Running \"${pl}\" to get \"${asm}\"")
            EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE}
                ${pl} "clang -fPIC -arch arm64 -mios-version-min=7.0.0 -fno-common -isysroot" ${asm}
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                OUTPUT_VARIABLE temp
                ERROR_VARIABLE error
            )
            if(error)
                message(FATAL_ERROR("Error while generating: ${error}"))
            endif(error)
        endforeach()
        SET(ssl_SRCS
        ssl/record/ssl3_record.c
         ssl/packet.c
         ssl/record/ssl3_buffer.c
         ssl/t1_enc.c
         ssl/ssl_utst.c
         ssl/statem/statem_srvr.c
         ssl/statem/statem_dtls.c
         ssl/d1_lib.c
         ssl/record/rec_layer_s3.c
         ssl/ssl_cert.c
         ssl/ssl_stat.c
         ssl/ssl_sess.c
         ssl/ssl_txt.c
         ssl/tls_srp.c
         ssl/ssl_conf.c
         ssl/d1_msg.c
         ssl/ssl_ciph.c
         ssl/record/dtls1_bitmap.c
         ssl/s3_msg.c
         ssl/ssl_mcnf.c
         ssl/ssl_init.c
         ssl/s3_cbc.c
         ssl/statem/statem.c
         ssl/statem/extensions_clnt.c
         ssl/statem/statem_lib.c
         ssl/s3_lib.c
         ssl/record/ssl3_record_tls13.c
         ssl/ssl_err.c
         ssl/ssl_lib.c
         ssl/ssl_asn1.c
         ssl/methods.c
         ssl/t1_trce.c
         ssl/pqueue.c
         ssl/s3_enc.c
         ssl/record/rec_layer_d1.c
         ssl/t1_lib.c
         ssl/ssl_rsa.c
         ssl/bio_ssl.c
         ssl/statem/extensions_srvr.c
         ssl/tls13_enc.c
         ssl/statem/statem_clnt.c
         ssl/d1_srtp.c
         ssl/statem/extensions.c
         ssl/statem/extensions_cust.c
        )

        add_library(ssl STATIC ${ssl_SRCS})

        TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR})
        TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  OPENSSL_PIC ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSLDIR="/usr/local/ssl" _REENTRANT NDEBUG)
        TARGET_COMPILE_OPTIONS(ssl PRIVATE  -fno-common -fPIC -mios-version-min=7.0.0)
        SET(crypto_SRCS
        crypto/cms/cms_ess.c
         crypto/evp/encode.c
         crypto/bio/b_sock2.c
         crypto/bn/bn_blind.c
         crypto/async/arch/async_null.c
         crypto/evp/m_sha1.c
         crypto/sm3/sm3.c
         crypto/blake2/m_blake2b.c
         crypto/dso/dso_lib.c
         crypto/x509/t_crl.c
         crypto/bn/bn_lib.c
         crypto/dh/dh_pmeth.c
         crypto/asn1/i2d_pu.c
         crypto/asn1/a_print.c
         crypto/chacha/chacha_enc.c
         crypto/cversion.c
         crypto/cms/cms_enc.c
         crypto/asn1/f_int.c
         crypto/bio/bss_mem.c
         crypto/dh/dh_prn.c
         crypto/x509/x509type.c
         crypto/ec/ecdh_ossl.c
         crypto/evp/evp_pkey.c
         crypto/evp/e_rc2.c
         crypto/dso/dso_win32.c
         crypto/dsa/dsa_meth.c
         crypto/rsa/rsa_meth.c
         crypto/rc2/rc2_cbc.c
         crypto/cast/c_ofb64.c
         crypto/pkcs12/p12_npas.c
         crypto/threads_win.c
         crypto/rc2/rc2ofb64.c
         crypto/asn1/a_type.c
         crypto/bio/bss_file.c
         crypto/x509v3/v3_int.c
         crypto/ct/ct_oct.c
         crypto/evp/e_aes_cbc_hmac_sha1.c
         crypto/x509/x509_err.c
         crypto/idea/i_cbc.c
         crypto/bn/bn_srp.c
         crypto/ocsp/ocsp_vfy.c
         crypto/rsa/rsa_prn.c
         crypto/des/cfb_enc.c
         crypto/rsa/rsa_pmeth.c
         crypto/asn1/a_digest.c
         crypto/des/fcrypt_b.c
         crypto/pkcs7/pk7_mime.c
         crypto/async/async.c
         crypto/txt_db/txt_db.c
         crypto/ec/ecp_nistp521.c
         crypto/x509v3/v3_alt.c
         crypto/rc4/rc4_skey.c
         crypto/siphash/siphash.c
         crypto/bn/bn_err.c
         crypto/x509/t_x509.c
         crypto/rsa/rsa_ameth.c
         crypto/kdf/scrypt.c
         crypto/sha/keccak1600.c
         crypto/sha/sha512.c
         crypto/asn1/asn_mime.c
         crypto/cast/c_enc.c
         crypto/pkcs12/p12_key.c
         crypto/conf/conf_mall.c
         crypto/rsa/rsa_ssl.c
         crypto/bn/bn_mul.c
         crypto/conf/conf_mod.c
         crypto/mdc2/mdc2dgst.c
         crypto/rsa/rsa_gen.c
         crypto/cmac/cm_pmeth.c
         crypto/ripemd/rmd_one.c
         crypto/evp/c_allc.c
         crypto/ebcdic.c
         crypto/asn1/p5_scrypt.c
         crypto/asn1/d2i_pr.c
         crypto/x509v3/v3_prn.c
         crypto/err/err_prn.c
         crypto/evp/e_des.c
         crypto/bio/bss_acpt.c
         crypto/asn1/ameth_lib.c
         crypto/dsa/dsa_sign.c
         crypto/evp/evp_key.c
         crypto/pkcs12/p12_init.c
         crypto/ts/ts_req_print.c
         crypto/pkcs12/p12_p8e.c
         crypto/dh/dh_depr.c
         crypto/cast/c_cfb64.c
         crypto/des/cbc_cksm.c
         crypto/x509/x509spki.c
         crypto/cast/c_ecb.c
         crypto/ec/ecp_oct.c
         crypto/evp/e_seed.c
         crypto/rand/rand_egd.c
         crypto/ec/ecp_nistp256.c
         crypto/dh/dh_err.c
         crypto/x509v3/v3_ia5.c
         crypto/modes/xts128.c
         crypto/asn1/t_pkey.c
         crypto/dso/dso_dl.c
         crypto/evp/evp_pbe.c
         crypto/x509/x509_req.c
         crypto/evp/bio_md.c
         crypto/asn1/a_object.c
         crypto/conf/conf_err.c
         crypto/bio/bio_cb.c
         crypto/whrlpool/wp_block.c
         crypto/asn1/asn1_err.c
         crypto/store/loader_file.c
         crypto/asn1/asn_moid.c
         crypto/evp/pmeth_gn.c
         crypto/evp/names.c
         crypto/cms/cms_env.c
         crypto/x509/x509_txt.c
         crypto/des/des_enc.c
         crypto/store/store_init.c
         crypto/x509v3/v3_purp.c
         crypto/threads_none.c
         crypto/des/ofb64ede.c
         crypto/x509/x509_cmp.c
         crypto/asn1/x_sig.c
         crypto/pkcs12/pk12err.c
         crypto/bn/bn_sqrt.c
         crypto/pkcs7/bio_pk7.c
         crypto/hmac/hmac.c
         crypto/conf/conf_sap.c
         crypto/cms/cms_kari.c
         crypto/bn/bn_prime.c
         crypto/sha/sha1_one.c
         crypto/x509v3/v3_cpols.c
         crypto/bf/bf_ecb.c
         crypto/sm4/sm4.c
         crypto/evp/p_seal.c
         crypto/rand/rand_unix.c
         crypto/bn/bn_const.c
         crypto/bio/bf_buff.c
         crypto/rsa/rsa_chk.c
         crypto/bio/bf_nbio.c
         crypto/evp/m_md5_sha1.c
         crypto/asn1/p5_pbe.c
         crypto/dh/dh_rfc5114.c
         crypto/asn1/asn1_par.c
         crypto/ec/ec_pmeth.c
         crypto/ec/ec2_oct.c
         crypto/ec/ecp_nistputil.c
         crypto/des/ecb3_enc.c
         crypto/hmac/hm_ameth.c
         crypto/des/cfb64enc.c
         crypto/asn1/x_long.c
         crypto/des/ecb_enc.c
         crypto/pkcs12/p12_mutl.c
         crypto/asn1/a_octet.c
         crypto/des/rand_key.c
         crypto/ec/curve448/curve448_tables.c
         crypto/x509v3/v3_bitst.c
         crypto/md5/md5_dgst.c
         crypto/x509/x_pubkey.c
         crypto/camellia/cmll_cbc.c
         crypto/evp/e_rc5.c
         crypto/des/ofb_enc.c
         crypto/poly1305/poly1305_pmeth.c
         crypto/ec/ec2_smpl.c
         crypto/cms/cms_pwri.c
         crypto/ec/curve448/arch_32/f_impl.c
         crypto/mem.c
         crypto/md4/md4_dgst.c
         crypto/evp/e_camellia.c
         crypto/ec/ec_key.c
         crypto/rand/rand_err.c
         crypto/x509/x_exten.c
         crypto/evp/e_xcbc_d.c
         crypto/asn1/a_verify.c
         crypto/srp/srp_vfy.c
         crypto/dh/dh_key.c
         crypto/asn1/asn_pack.c
         crypto/ec/ecdsa_vrf.c
         crypto/ec/ec_print.c
         crypto/evp/e_rc4.c
         crypto/x509v3/pcy_data.c
         crypto/x509/x509_meth.c
         crypto/ripemd/rmd_dgst.c
         crypto/bn/bn_sqr.c
         crypto/camellia/cmll_cfb.c
         crypto/dso/dso_dlfcn.c
         crypto/ec/ecdsa_ossl.c
         crypto/x509v3/v3_extku.c
         crypto/bio/b_dump.c
         crypto/cast/c_skey.c
         crypto/sha/sha256.c
         crypto/cms/cms_dd.c
         crypto/x509v3/v3_admis.c
         crypto/des/xcbc_enc.c
         crypto/x509v3/v3_pcia.c
         crypto/aes/aes_misc.c
         crypto/bio/b_addr.c
         crypto/pkcs12/p12_sbag.c
         crypto/cms/cms_err.c
         crypto/asn1/a_utf8.c
         crypto/evp/e_idea.c
         crypto/buffer/buffer.c
         crypto/threads_pthread.c
         crypto/x509/x509name.c
         crypto/bn/bn_ctx.c
         crypto/ec/ec_check.c
         crypto/x509/x509_vfy.c
         crypto/ct/ct_sct.c
         crypto/rsa/rsa_x931g.c
         crypto/evp/e_sm4.c
         crypto/asn1/a_strex.c
         crypto/modes/ofb128.c
         crypto/ui/ui_lib.c
         crypto/ct/ct_prn.c
         crypto/bio/bss_null.c
         crypto/rsa/rsa_mp.c
         crypto/asn1/bio_ndef.c
         crypto/x509v3/v3_crld.c
         crypto/dsa/dsa_vrf.c
         crypto/stack/stack.c
         crypto/o_fopen.c
         crypto/des/set_key.c
         crypto/bio/bss_fd.c
         crypto/sm2/sm2_sign.c
         crypto/bio/bss_sock.c
         crypto/evp/evp_enc.c
         crypto/ec/ec_kmeth.c
         crypto/modes/ocb128.c
         crypto/x509/x_x509a.c
         crypto/evp/bio_enc.c
         crypto/pkcs12/p12_crpt.c
         crypto/comp/comp_lib.c
         crypto/rand/rand_lib.c
         crypto/evp/m_sigver.c
         crypto/x509v3/v3_skey.c
         crypto/evp/m_md2.c
         crypto/ocsp/v3_ocsp.c
         crypto/asn1/evp_asn1.c
         crypto/pkcs12/p12_utl.c
         crypto/pem/pem_err.c
         crypto/ec/curve448/curve448.c
         crypto/x509/x_x509.c
         crypto/asn1/a_i2d_fp.c
         crypto/ui/ui_err.c
         crypto/evp/cmeth_lib.c
         crypto/dh/dh_lib.c
         crypto/ts/ts_rsp_sign.c
         crypto/evp/m_mdc2.c
         crypto/evp/e_null.c
         crypto/x509/by_file.c
         crypto/ct/ct_log.c
         crypto/pem/pem_xaux.c
         crypto/evp/p_open.c
         crypto/asn1/a_dup.c
         crypto/bn/bn_asm.c
         crypto/ctype.c
         crypto/ec/ecx_meth.c
         crypto/ec/ec_lib.c
         crypto/rsa/rsa_err.c
         crypto/o_init.c
         crypto/hmac/hm_pmeth.c
         crypto/pem/pem_sign.c
         crypto/rand/randfile.c
         crypto/pkcs7/pk7_lib.c
         crypto/camellia/cmll_ofb.c
         crypto/asn1/t_spki.c
         crypto/aes/aes_ecb.c
         crypto/rc4/rc4_enc.c
         crypto/asn1/tasn_scn.c
         crypto/x509/x509_r2x.c
         crypto/asn1/a_int.c
         crypto/dso/dso_vms.c
         crypto/modes/ctr128.c
         crypto/bio/bss_conn.c
         crypto/asn1/a_sign.c
         crypto/evp/bio_ok.c
         crypto/sm2/sm2_err.c
         crypto/ct/ct_b64.c
         crypto/pkcs7/pk7_smime.c
         crypto/evp/m_wp.c
         crypto/asn1/tasn_typ.c
         crypto/ocsp/ocsp_asn.c
         crypto/des/cbc_enc.c
         crypto/evp/e_old.c
         crypto/x509/x509_def.c
         crypto/x509v3/v3_pcons.c
         crypto/blake2/m_blake2s.c
         crypto/dsa/dsa_prn.c
         crypto/asn1/d2i_pu.c
         crypto/ocsp/ocsp_lib.c
         crypto/cms/cms_lib.c
         crypto/evp/digest.c
         crypto/lhash/lhash.c
         crypto/x509/x509_v3.c
         crypto/pkcs12/p12_crt.c
         crypto/asn1/x_spki.c
         crypto/asn1/a_bitstr.c
         crypto/objects/obj_xref.c
         crypto/x509/x_attrib.c
         crypto/dsa/dsa_err.c
         crypto/ec/ecdh_kdf.c
         crypto/asn1/tasn_utl.c
         crypto/store/store_lib.c
         crypto/bn/bn_add.c
         crypto/bn/bn_print.c
         crypto/comp/c_zlib.c
         crypto/bio/bss_dgram.c
         crypto/ec/eck_prn.c
         crypto/x509v3/v3_pci.c
         crypto/async/arch/async_posix.c
         crypto/sm2/sm2_crypt.c
         crypto/ec/ec_cvt.c
         crypto/x509v3/v3_lib.c
         crypto/ec/ecp_nist.c
         crypto/blake2/blake2s.c
         crypto/bn/bn_dh.c
         crypto/comp/comp_err.c
         crypto/dsa/dsa_gen.c
         crypto/evp/pmeth_fn.c
         crypto/seed/seed_cbc.c
         crypto/err/err.c
         crypto/ocsp/ocsp_prn.c
         crypto/rand/rand_vms.c
         crypto/asn1/tasn_prn.c
         crypto/x509v3/v3_genn.c
         crypto/idea/i_ofb64.c
         crypto/bf/bf_cfb64.c
         crypto/blake2/blake2b.c
         crypto/asn1/p8_pkey.c
         crypto/x509v3/v3_bcons.c
         crypto/objects/o_names.c
         crypto/bn/bn_div.c
         crypto/x509v3/v3_asid.c
         crypto/bn/bn_recp.c
         crypto/pkcs12/p12_asn.c
         crypto/objects/obj_lib.c
         crypto/bn/bn_gcd.c
         crypto/sm3/m_sm3.c
         crypto/cms/cms_asn1.c
         crypto/store/store_register.c
         crypto/rsa/rsa_none.c
         crypto/rsa/rsa_pk1.c
         crypto/evp/evp_lib.c
         crypto/ec/ec_ameth.c
         crypto/ocsp/ocsp_srv.c
         crypto/modes/ccm128.c
         crypto/evp/m_null.c
         crypto/x509/x509_vpm.c
         crypto/modes/wrap128.c
         crypto/pem/pvkfmt.c
         crypto/asn1/a_mbstr.c
         crypto/dh/dh_ameth.c
         crypto/asn1/asn1_lib.c
         crypto/ts/ts_lib.c
         crypto/bio/bio_err.c
         crypto/ts/ts_asn1.c
         crypto/evp/m_sha3.c
         crypto/ui/ui_null.c
         crypto/conf/conf_api.c
         crypto/bf/bf_skey.c
         crypto/aes/aes_wrap.c
         crypto/bn/bn_kron.c
         crypto/bn/bn_exp2.c
         crypto/rsa/rsa_asn1.c
         crypto/evp/e_bf.c
         crypto/ts/ts_rsp_print.c
         crypto/whrlpool/wp_dgst.c
         crypto/store/store_strings.c
         crypto/buffer/buf_err.c
         crypto/x509/x509rset.c
         crypto/seed/seed_ofb.c
         crypto/modes/gcm128.c
         crypto/aes/aes_ige.c
         crypto/evp/m_md5.c
         crypto/dsa/dsa_key.c
         crypto/uid.c
         crypto/evp/e_des3.c
         crypto/o_fips.c
         crypto/cpt_err.c
         crypto/pkcs7/pk7_asn1.c
         crypto/cmac/cm_ameth.c
         crypto/evp/p_lib.c
         crypto/conf/conf_lib.c
         crypto/ec/ecp_smpl.c
         crypto/pkcs7/pkcs7err.c
         crypto/ocsp/ocsp_cl.c
         crypto/rand/drbg_ctr.c
         crypto/des/str2key.c
         crypto/async/async_err.c
         crypto/bio/bss_log.c
         crypto/ec/curve25519.c
         crypto/async/async_wait.c
         crypto/mem_clr.c
         crypto/evp/e_chacha20_poly1305.c
         crypto/idea/i_ecb.c
         crypto/evp/p5_crpt.c
         crypto/ex_data.c
         crypto/ts/ts_verify_ctx.c
         crypto/x509/x509_set.c
         crypto/evp/p_verify.c
         crypto/dh/dh_rfc7919.c
         crypto/bio/b_sock.c
         crypto/rsa/rsa_x931.c
         crypto/x509/x509_d2.c
         crypto/evp/pbe_scrypt.c
         crypto/srp/srp_lib.c
         crypto/bn/bn_mod.c
         crypto/rsa/rsa_lib.c
         crypto/objects/obj_err.c
         crypto/dso/dso_openssl.c
         crypto/dsa/dsa_asn1.c
         crypto/bn/bn_mont.c
         crypto/x509/x_name.c
         crypto/asn1/x_val.c
         crypto/dh/dh_check.c
         crypto/evp/e_aes.c
         crypto/mdc2/mdc2_one.c
         crypto/getenv.c
         crypto/ocsp/ocsp_err.c
         crypto/rc2/rc2cfb64.c
         crypto/x509/by_dir.c
         crypto/rc2/rc2_skey.c
         crypto/bn/bn_gf2m.c
         crypto/asn1/n_pkey.c
         crypto/bn/bn_shift.c
         crypto/asn1/x_pkey.c
         crypto/bf/bf_ofb64.c
         crypto/asn1/tasn_enc.c
         crypto/evp/e_aria.c
         crypto/asn1/a_gentm.c
         crypto/pkcs12/p12_add.c
         crypto/dh/dh_meth.c
         crypto/x509v3/v3_pmaps.c
         crypto/ts/ts_req_utils.c
         crypto/pkcs12/p12_decr.c
         crypto/cms/cms_cd.c
         crypto/pem/pem_pkey.c
         crypto/des/pcbc_enc.c
         crypto/ec/ecp_mont.c
         crypto/bio/bio_meth.c
         crypto/seed/seed_cfb.c
         crypto/x509v3/v3err.c
         crypto/pkcs12/p12_kiss.c
         crypto/dsa/dsa_depr.c
         crypto/o_dir.c
         crypto/ec/ec_mult.c
         crypto/o_str.c
         crypto/bf/bf_enc.c
         crypto/ec/ec_oct.c
         crypto/x509v3/v3_addr.c
         crypto/bn/bn_mpi.c
         crypto/evp/m_md4.c
         crypto/mem_dbg.c
         crypto/rand/drbg_lib.c
         crypto/pem/pem_info.c
         crypto/x509v3/pcy_node.c
         crypto/evp/e_rc4_hmac_md5.c
         crypto/err/err_all.c
         crypto/aria/aria.c
         crypto/sm2/sm2_pmeth.c
         crypto/asn1/a_utctm.c
         crypto/asn1/bio_asn1.c
         crypto/asn1/i2d_pr.c
         crypto/ts/ts_rsp_verify.c
         crypto/x509v3/pcy_cache.c
         crypto/x509/x509_att.c
         crypto/siphash/siphash_ameth.c
         crypto/pem/pem_lib.c
         crypto/aes/aes_cfb.c
         crypto/ui/ui_util.c
         crypto/asn1/asn1_item_list.c
         crypto/des/ofb64enc.c
         crypto/pem/pem_oth.c
         crypto/aes/aes_cbc.c
         crypto/cryptlib.c
         crypto/ct/ct_policy.c
         crypto/asn1/x_bignum.c
         crypto/kdf/kdf_err.c
         crypto/x509v3/pcy_map.c
         crypto/x509v3/v3_akeya.c
         crypto/pkcs7/pk7_doit.c
         crypto/bio/bf_lbuf.c
         crypto/ct/ct_sct_ctx.c
         crypto/x509/t_req.c
         crypto/x509v3/pcy_lib.c
         crypto/pkcs7/pk7_attr.c
         crypto/conf/conf_ssl.c
         crypto/seed/seed.c
         crypto/bn/bn_intern.c
         crypto/ocsp/ocsp_ht.c
         crypto/o_time.c
         crypto/rsa/rsa_crpt.c
         crypto/pkcs12/p12_p8d.c
         crypto/md5/md5_one.c
         crypto/asn1/x_int64.c
         crypto/evp/m_ripemd.c
         crypto/ct/ct_x509v3.c
         crypto/rc2/rc2_ecb.c
         crypto/rsa/rsa_depr.c
         crypto/asn1/t_bitst.c
         crypto/des/qud_cksm.c
         crypto/evp/bio_b64.c
         crypto/des/fcrypt.c
         crypto/ec/ec_curve.c
         crypto/rsa/rsa_ossl.c
         crypto/rsa/rsa_oaep.c
         crypto/ocsp/ocsp_ext.c
         crypto/modes/cbc128.c
         crypto/x509v3/v3_info.c
         crypto/cms/cms_sd.c
         crypto/pkcs12/p12_attr.c
         crypto/bio/bss_bio.c
         crypto/evp/p5_crpt2.c
         crypto/bn/bn_depr.c
         crypto/asn1/p5_pbev2.c
         crypto/camellia/cmll_ctr.c
         crypto/x509/x_req.c
         crypto/ct/ct_err.c
         crypto/bio/bio_lib.c
         crypto/x509/x509_trs.c
         crypto/pem/pem_all.c
         crypto/asn1/a_d2i_fp.c
         crypto/pem/pem_pk8.c
         crypto/seed/seed_ecb.c
         crypto/poly1305/poly1305_ameth.c
         crypto/evp/e_cast.c
         crypto/evp/c_alld.c
         crypto/asn1/a_time.c
         crypto/bn/bn_x931p.c
         crypto/camellia/cmll_ecb.c
         crypto/x509/x509cset.c
         crypto/evp/e_aes_cbc_hmac_sha256.c
         crypto/x509v3/v3_pku.c
         crypto/aes/aes_ofb.c
         crypto/asn1/tasn_dec.c
         crypto/x509v3/v3_utl.c
         crypto/ec/ec_err.c
         crypto/evp/evp_cnf.c
         crypto/x509/x509_ext.c
         crypto/asn1/asn1_gen.c
         crypto/des/cfb64ede.c
         crypto/asn1/a_strnid.c
         crypto/camellia/camellia.c
         crypto/objects/obj_dat.c
         crypto/evp/pmeth_lib.c
         crypto/siphash/siphash_pmeth.c
         crypto/cms/cms_att.c
         crypto/ec/ec_asn1.c
         crypto/asn1/x_info.c
         crypto/dh/dh_gen.c
         crypto/cmac/cmac.c
         crypto/dsa/dsa_ossl.c
         crypto/ec/curve448/scalar.c
         crypto/bn/bn_rand.c
         crypto/x509v3/v3_sxnet.c
         crypto/ts/ts_rsp_utils.c
         crypto/kdf/tls1_prf.c
         crypto/evp/evp_err.c
         crypto/rsa/rsa_pss.c
         crypto/dh/dh_kdf.c
         crypto/dso/dso_err.c
         crypto/cms/cms_io.c
         crypto/dh/dh_asn1.c
         crypto/ec/ecdsa_sign.c
         crypto/dsa/dsa_lib.c
         crypto/bn/bn_word.c
         crypto/x509v3/pcy_tree.c
         crypto/x509/x509_obj.c
         crypto/evp/p_sign.c
         crypto/asn1/tasn_fre.c
         crypto/x509/x509_lu.c
         crypto/mem_sec.c
         crypto/asn1/nsseq.c
         crypto/ts/ts_conf.c
         crypto/camellia/cmll_misc.c
         crypto/idea/i_cfb64.c
         crypto/x509v3/v3_conf.c
         crypto/asn1/x_algor.c
         crypto/aes/aes_core.c
         crypto/bn/bn_nist.c
         crypto/lhash/lh_stats.c
         crypto/asn1/asn_mstbl.c
         crypto/modes/cfb128.c
         crypto/store/store_err.c
         crypto/ui/ui_openssl.c
         crypto/conf/conf_def.c
         crypto/x509/x_all.c
         crypto/x509/x_crl.c
         crypto/x509v3/v3_akey.c
         crypto/asn1/tasn_new.c
         crypto/evp/p_dec.c
         crypto/bio/bf_null.c
         crypto/bn/bn_exp.c
         crypto/kdf/hkdf.c
         crypto/init.c
         crypto/dsa/dsa_pmeth.c
         crypto/rand/rand_win.c
         crypto/cms/cms_smime.c
         crypto/ec/ecp_nistp224.c
         crypto/ct/ct_vfy.c
         crypto/asn1/f_string.c
         crypto/pem/pem_x509.c
         crypto/x509v3/v3_tlsf.c
         crypto/evp/p_enc.c
         crypto/modes/cts128.c
         crypto/sha/sha1dgst.c
         crypto/ec/curve448/eddsa.c
         crypto/ec/curve448/f_generic.c
         crypto/md4/md4_one.c
         crypto/async/arch/async_win.c
         crypto/x509v3/v3_ncons.c
         crypto/rsa/rsa_saos.c
         crypto/x509v3/v3_enum.c
         crypto/dsa/dsa_ameth.c
         crypto/poly1305/poly1305.c
         crypto/ts/ts_err.c
         crypto/rsa/rsa_sign.c
         crypto/bio/b_print.c
         crypto/idea/i_skey.c
        )

        add_library(crypto STATIC ${crypto_SRCS})

        TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE include crypto crypto/ec/curve448 crypto/include crypto/ec/curve448/arch_32 crypto/modes ${CMAKE_CURRENT_SOURCE_DIR})
        TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  OPENSSL_PIC ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSLDIR="/usr/local/ssl" _REENTRANT NDEBUG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-common -fPIC -mios-version-min=7.0.0")
        

elseif(CMAKE_OSX_SYSROOT MATCHES MacOSX)

set(arch "darwin64-x86_64-cc")
    find_program(PERL_EXECUTABLE perl)
    if(NOT PERL_EXECUTABLE)
        message(FATAL_ERROR("Perl not found"))
    endif(NOT PERL_EXECUTABLE)

    message("Configuring configdata.pm for \"${arch}\"")
    
    EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} Configure ${arch} 

            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE TEMP
            ERROR_VARIABLE ERROR
    )
    if(ERROR)
        MESSAGE(FATAL_ERROR("Error while configuring: ${ERROR}"))
    endif(ERROR)

    EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} util/mkbuildinf.pl "clang -fPIC -arch x86_64 -O3 -Wall -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_CPUID_OBJ -DOPENSSL_IA32_SSE2 -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_MONT5 -DOPENSSL_BN_ASM_GF2m -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DKECCAK1600_ASM -DRC4_ASM -DMD5_ASM -DVPAES_ASM -DGHASH_ASM -DECP_NISTZ256_ASM -DX25519_ASM -DPOLY1305_ASM -D_REENTRANT -DNDEBUG" ""darwin64-x86_64-cc"" 
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        OUTPUT_FILE crypto/buildinf.h
        ERROR_VARIABLE ERROR)
    if(ERROR)
        MESSAGE(FATAL_ERROR("Error while generating mkbuildinf: ${ERROR}"))
    endif(ERROR)

    foreach(el crypto/include/internal/bn_conf.h;crypto/include/internal/dso_conf.h;include/openssl/opensslconf.h)
        MESSAGE("Generating ${el}")
        EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE}
            "-I${CMAKE_CURRENT_LIST_DIR}" -Mconfigdata "util/dofile.pl" "-oMakefile" ${el}.in
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_FILE ${el}
            ERROR_VARIABLE error)
        if(error)
            message(FATAL_ERROR("Error while generating: ${error}"))
        endif(error)
    endforeach()
    
    set(PLs crypto/aes/asm/aesni-mb-x86_64.pl crypto/aes/asm/aesni-sha1-x86_64.pl crypto/aes/asm/aesni-sha256-x86_64.pl crypto/aes/asm/aesni-x86_64.pl crypto/aes/asm/vpaes-x86_64.pl crypto/bn/asm/rsaz-avx2.pl crypto/bn/asm/rsaz-x86_64.pl crypto/bn/asm/x86_64-gf2m.pl crypto/bn/asm/x86_64-mont.pl crypto/bn/asm/x86_64-mont5.pl crypto/camellia/asm/cmll-x86_64.pl crypto/chacha/asm/chacha-x86_64.pl crypto/ec/asm/ecp_nistz256-x86_64.pl crypto/ec/asm/x25519-x86_64.pl crypto/md5/asm/md5-x86_64.pl crypto/modes/asm/aesni-gcm-x86_64.pl crypto/modes/asm/ghash-x86_64.pl crypto/poly1305/asm/poly1305-x86_64.pl crypto/rc4/asm/rc4-md5-x86_64.pl crypto/rc4/asm/rc4-x86_64.pl crypto/sha/asm/keccak1600-x86_64.pl crypto/sha/asm/sha1-mb-x86_64.pl crypto/sha/asm/sha1-x86_64.pl crypto/sha/asm/sha256-mb-x86_64.pl crypto/sha/asm/sha512-x86_64.pl crypto/sha/asm/sha512-x86_64.pl crypto/whrlpool/asm/wp-x86_64.pl crypto/x86_64cpuid.pl engines/asm/e_padlock-x86_64.pl)
    set(ASMs crypto/aes/aesni-mb-x86_64.s crypto/aes/aesni-sha1-x86_64.s crypto/aes/aesni-sha256-x86_64.s crypto/aes/aesni-x86_64.s crypto/aes/vpaes-x86_64.s crypto/bn/rsaz-avx2.s crypto/bn/rsaz-x86_64.s crypto/bn/x86_64-gf2m.s crypto/bn/x86_64-mont.s crypto/bn/x86_64-mont5.s crypto/camellia/cmll-x86_64.s crypto/chacha/chacha-x86_64.s crypto/ec/ecp_nistz256-x86_64.s crypto/ec/x25519-x86_64.s crypto/md5/md5-x86_64.s crypto/modes/aesni-gcm-x86_64.s crypto/modes/ghash-x86_64.s crypto/poly1305/poly1305-x86_64.s crypto/rc4/rc4-md5-x86_64.s crypto/rc4/rc4-x86_64.s crypto/sha/keccak1600-x86_64.s crypto/sha/sha1-mb-x86_64.s crypto/sha/sha1-x86_64.s crypto/sha/sha256-mb-x86_64.s crypto/sha/sha256-x86_64.s crypto/sha/sha512-x86_64.s crypto/whrlpool/wp-x86_64.s crypto/x86_64cpuid.s engines/e_padlock-x86_64.s)
    list(LENGTH PLs _len)
    math(EXPR len "${_len}-1")
    foreach(idx RANGE ${len})

        list(GET PLs ${idx} pl)
        list(GET ASMs ${idx} asm)
        MESSAGE("Running \"${pl}\" to get \"${asm}\"")
        EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE}
            ${pl} macosx ${asm}
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE temp
            ERROR_VARIABLE error
        )
        if(error)
            message(FATAL_ERROR("Error while generating: ${error}"))
        endif(error)
    endforeach()
        
    SET(ssl_SRCS
        ${COMMON_ssl_SRCS}
        
    )

    add_library(ssl STATIC ${ssl_SRCS})

    TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR})
    TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  MD5_ASM POLY1305_ASM X25519_ASM RC4_ASM OPENSSL_CPUID_OBJ OPENSSLDIR="/usr/local/ssl" ECP_NISTZ256_ASM VPAES_ASM SHA256_ASM OPENSSL_BN_ASM_MONT5 _REENTRANT NDEBUG OPENSSL_IA32_SSE2 SHA1_ASM OPENSSL_PIC SHA512_ASM L_ENDIAN GHASH_ASM ENGINESDIR="/usr/local/lib/engines-1.1" KECCAK1600_ASM OPENSSL_BN_ASM_MONT OPENSSL_BN_ASM_GF2m)
    TARGET_COMPILE_OPTIONS(ssl PRIVATE -fPIC )
    
    SET(crypto_SRCS
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

    TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE crypto/modes include ${CMAKE_CURRENT_SOURCE_DIR} crypto/ec/curve448/arch_32 crypto crypto/include crypto/ec/curve448)
    TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  MD5_ASM POLY1305_ASM X25519_ASM RC4_ASM OPENSSL_CPUID_OBJ OPENSSLDIR="/usr/local/ssl" ECP_NISTZ256_ASM VPAES_ASM SHA256_ASM OPENSSL_BN_ASM_MONT5 _REENTRANT NDEBUG OPENSSL_IA32_SSE2 SHA1_ASM OPENSSL_PIC SHA512_ASM L_ENDIAN GHASH_ASM ENGINESDIR="/usr/local/lib/engines-1.1" KECCAK1600_ASM OPENSSL_BN_ASM_MONT OPENSSL_BN_ASM_GF2m)
    TARGET_COMPILE_OPTIONS(crypto PRIVATE -fPIC )
elseif(CMAKE_OSX_SYSROOT MATCHES iPhoneOS)

    set(arch "ios-cross")
    find_program(PERL_EXECUTABLE perl)
    if(NOT PERL_EXECUTABLE)
        message(FATAL_ERROR("Perl not found"))
    endif(NOT PERL_EXECUTABLE)

    message("Configuring configdata.pm for \"${arch}\"")
    
    EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} Configure ${arch} 

            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE TEMP
            ERROR_VARIABLE ERROR
    )
    if(ERROR)
        MESSAGE(FATAL_ERROR("Error while configuring: ${ERROR}"))
    endif(ERROR)

    EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} util/mkbuildinf.pl "clang -fPIC -arch arm64 -mios-version-min=7.0.0 -fno-common -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer//SDKs/iPhoneOS.sdk -O3 -DOPENSSL_PIC -D_REENTRANT -DNDEBUG" ""ios64-cross"" 
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        OUTPUT_FILE crypto/buildinf.h
        ERROR_VARIABLE ERROR)
    if(ERROR)
        MESSAGE(FATAL_ERROR("Error while generating mkbuildinf: ${ERROR}"))
    endif(ERROR)

    foreach(el crypto/include/internal/bn_conf.h;crypto/include/internal/dso_conf.h;include/openssl/opensslconf.h)
        MESSAGE("Generating ${el}")
        EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE}
            "-I${CMAKE_CURRENT_LIST_DIR}" -Mconfigdata "util/dofile.pl" "-oMakefile" ${el}.in
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_FILE ${el}
            ERROR_VARIABLE error)
        if(error)
            message(FATAL_ERROR("Error while generating: ${error}"))
        endif(error)
    endforeach()
    
    SET(ssl_SRCS
        ${COMMON_ssl_SRCS}
        
    )

    add_library(ssl STATIC ${ssl_SRCS})

    TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
    TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  _REENTRANT NDEBUG OPENSSLDIR="/usr/local/ssl" ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSL_PIC)
    TARGET_COMPILE_OPTIONS(ssl PRIVATE -mios-version-min=7.0.0 -fno-common -fPIC )
    
    SET(crypto_SRCS
        ${COMMON_crypto_SRCS}
        crypto/bf/bf_enc.c crypto/camellia/cmll_cbc.c crypto/sha/keccak1600.c
        crypto/mem_clr.c crypto/camellia/cmll_misc.c crypto/whrlpool/wp_block.c
        crypto/rc4/rc4_skey.c crypto/rc4/rc4_enc.c crypto/chacha/chacha_enc.c
        crypto/aes/aes_core.c crypto/bn/bn_asm.c crypto/des/fcrypt_b.c
        crypto/camellia/camellia.c crypto/des/des_enc.c
    )

    add_library(crypto STATIC ${crypto_SRCS})

    TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE crypto/ec/curve448/arch_32 crypto/include include ${CMAKE_CURRENT_SOURCE_DIR} crypto/modes crypto/ec/curve448 crypto)
    TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  _REENTRANT NDEBUG OPENSSLDIR="/usr/local/ssl" ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSL_PIC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mios-version-min=7.0.0 -fno-common -fPIC ")
        
elseif(ANDROID)
    IF(${ANDROID_ABI} STREQUAL "x86_64")
        set(arch "android-x86_64")
        message("Building ${arch}")
        
        file(COPY android/${arch}/opensslconf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/openssl/)
        file(COPY android/${arch}/bn_conf.h android/${arch}/dso_conf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/internal/openssl/)
        file(COPY android/${arch}/buildinf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/)
            
        SET(ssl_SRCS
            ${COMMON_ssl_SRCS}
        )

        add_library(ssl STATIC ${ssl_SRCS})

        TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
        TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  NDEBUG OPENSSL_USE_NODELETE OPENSSL_PIC ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSLDIR="/usr/local/ssl")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -pthread ")
        
        SET(crypto_SRCS
            ${COMMON_crypto_SRCS}
            crypto/engine/eng_all.c crypto/rc4/rc4_enc.c crypto/camellia/camellia.c
            crypto/engine/eng_rdrand.c crypto/engine/tb_cipher.c crypto/camellia/cmll_cbc.c
            crypto/engine/eng_cnf.c crypto/engine/eng_openssl.c crypto/engine/tb_rand.c
            crypto/engine/eng_err.c crypto/engine/tb_eckey.c crypto/engine/eng_init.c
            crypto/chacha/chacha_enc.c crypto/engine/eng_lib.c crypto/engine/eng_dyn.c
            crypto/engine/eng_ctrl.c crypto/engine/eng_list.c crypto/engine/tb_pkmeth.c
            crypto/engine/eng_pkey.c crypto/sha/keccak1600.c crypto/engine/tb_rsa.c
            crypto/engine/tb_dsa.c crypto/mem_clr.c crypto/bn/bn_asm.c
            crypto/engine/tb_dh.c crypto/engine/tb_asnmth.c crypto/engine/eng_table.c
            crypto/engine/eng_fat.c crypto/whrlpool/wp_block.c crypto/engine/tb_digest.c
            crypto/rc4/rc4_skey.c
        )

        add_library(crypto STATIC ${crypto_SRCS})

        TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE crypto/modes crypto crypto/ec/curve448 crypto/include ${CMAKE_CURRENT_SOURCE_DIR} include crypto/ec/curve448/arch_32)
        TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  NDEBUG OPENSSL_USE_NODELETE OPENSSL_PIC ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSLDIR="/usr/local/ssl")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -pthread ")

        ELSEIF(${ANDROID_ABI} STREQUAL "x86")
            set(arch "android-x86")
            message("Building ${arch}")
            file(COPY android/${arch}/opensslconf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/openssl/)
            file(COPY android/${arch}/bn_conf.h android/${arch}/dso_conf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/internal/openssl/)
            file(COPY android/${arch}/buildinf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/)

            SET(ssl_SRCS
                ${COMMON_ssl_SRCS}
            )

            add_library(ssl STATIC ${ssl_SRCS})

            TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
            TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSL_PIC OPENSSLDIR="/usr/local/ssl" OPENSSL_USE_NODELETE NDEBUG)
            SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fomit-frame-pointer -pthread  -fPIC")
            
            SET(crypto_SRCS
                ${COMMON_crypto_SRCS}
                crypto/engine/eng_ctrl.c crypto/engine/tb_eckey.c crypto/bn/bn_asm.c
                crypto/engine/tb_pkmeth.c crypto/whrlpool/wp_block.c crypto/engine/eng_cnf.c
                crypto/engine/eng_rdrand.c crypto/camellia/camellia.c crypto/rc4/rc4_skey.c
                crypto/engine/eng_table.c crypto/engine/tb_cipher.c crypto/engine/tb_rsa.c
                crypto/engine/tb_asnmth.c crypto/engine/eng_pkey.c crypto/mem_clr.c
                crypto/engine/eng_init.c crypto/engine/tb_dsa.c crypto/sha/keccak1600.c
                crypto/rc4/rc4_enc.c crypto/engine/eng_err.c crypto/engine/tb_rand.c
                crypto/camellia/cmll_cbc.c crypto/chacha/chacha_enc.c crypto/engine/eng_lib.c
                crypto/aes/aes_core.c crypto/engine/eng_dyn.c crypto/engine/eng_openssl.c
                crypto/engine/eng_list.c crypto/engine/eng_all.c crypto/engine/eng_fat.c
                crypto/engine/tb_dh.c crypto/engine/tb_digest.c
            )

            add_library(crypto STATIC ${crypto_SRCS})

            TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE crypto/ec/curve448/arch_32 crypto/modes ${CMAKE_CURRENT_SOURCE_DIR} include crypto/ec/curve448 crypto crypto/include)
            TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSL_PIC OPENSSLDIR="/usr/local/ssl" OPENSSL_USE_NODELETE NDEBUG)
            SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fomit-frame-pointer -pthread  -fPIC")
        
    ELSEIF(${ANDROID_ABI} STREQUAL "armeabi-v7a")
        set(arch "android-arm")
        message("Building ${arch}")
        
        file(COPY android/${arch}/opensslconf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/openssl/)
        file(COPY android/${arch}/bn_conf.h android/${arch}/dso_conf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/internal/openssl/)
        file(COPY android/${arch}/buildinf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/)
            
        SET(ssl_SRCS
            ${COMMON_ssl_SRCS}
        )

        add_library(ssl STATIC ${ssl_SRCS})

        TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR})
        TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  NDEBUG OPENSSL_PIC OPENSSLDIR="/usr/local/ssl" OPENSSL_USE_NODELETE ENGINESDIR="/usr/local/lib/engines-1.1")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread -fPIC")
        
        SET(crypto_SRCS
            ${COMMON_crypto_SRCS}
            crypto/engine/tb_cipher.c crypto/engine/tb_asnmth.c crypto/engine/tb_pkmeth.c
            crypto/engine/eng_fat.c crypto/chacha/chacha_enc.c crypto/engine/eng_err.c
            crypto/engine/eng_list.c crypto/engine/tb_rsa.c crypto/rc4/rc4_enc.c
            crypto/engine/eng_all.c crypto/engine/eng_table.c crypto/engine/tb_eckey.c
            crypto/engine/tb_dh.c crypto/engine/eng_rdrand.c crypto/engine/tb_rand.c
            crypto/engine/eng_dyn.c crypto/whrlpool/wp_block.c crypto/mem_clr.c
            crypto/sha/keccak1600.c crypto/camellia/cmll_cbc.c crypto/engine/eng_ctrl.c
            crypto/engine/eng_lib.c crypto/rc4/rc4_skey.c crypto/engine/tb_dsa.c
            crypto/engine/eng_pkey.c crypto/engine/eng_cnf.c crypto/engine/eng_openssl.c
            crypto/engine/tb_digest.c crypto/bn/bn_asm.c crypto/camellia/camellia.c
            crypto/engine/eng_init.c
        )

        add_library(crypto STATIC ${crypto_SRCS})

        TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE crypto/include crypto crypto/modes ${CMAKE_CURRENT_SOURCE_DIR} crypto/ec/curve448/arch_32 crypto/ec/curve448 include)
        TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  NDEBUG OPENSSL_PIC OPENSSLDIR="/usr/local/ssl" OPENSSL_USE_NODELETE ENGINESDIR="/usr/local/lib/engines-1.1")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread -fPIC")

    ELSEIF(${ANDROID_ABI} STREQUAL "arm64-v8a")
        set(arch "android-arm64")
        message("Building ${arch}")
        
        file(COPY android/${arch}/opensslconf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/openssl/)
        file(COPY android/${arch}/bn_conf.h android/${arch}/dso_conf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/internal/openssl/)
        file(COPY android/${arch}/buildinf.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/crypto/)
            
        SET(ssl_SRCS
            ${COMMON_ssl_SRCS}
            
        )

        add_library(ssl STATIC ${ssl_SRCS})

        TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
        TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  OPENSSL_PIC ENGINESDIR="/usr/local/lib/engines-1.1" NDEBUG OPENSSL_USE_NODELETE OPENSSLDIR="/usr/local/ssl")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC  -pthread")
        
        SET(crypto_SRCS
            ${COMMON_crypto_SRCS}
            crypto/engine/tb_asnmth.c crypto/engine/tb_rsa.c crypto/engine/eng_pkey.c
            crypto/engine/tb_cipher.c crypto/engine/eng_fat.c crypto/chacha/chacha_enc.c
            crypto/engine/tb_dsa.c crypto/engine/eng_list.c crypto/engine/tb_eckey.c
            crypto/camellia/camellia.c crypto/rc4/rc4_enc.c crypto/engine/eng_cnf.c
            crypto/engine/tb_digest.c crypto/engine/eng_ctrl.c crypto/engine/eng_all.c
            crypto/mem_clr.c crypto/engine/tb_pkmeth.c crypto/engine/eng_err.c
            crypto/sha/keccak1600.c crypto/engine/eng_rdrand.c crypto/rc4/rc4_skey.c
            crypto/engine/eng_init.c crypto/whrlpool/wp_block.c crypto/bn/bn_asm.c
            crypto/engine/eng_lib.c crypto/engine/eng_dyn.c crypto/engine/tb_rand.c
            crypto/engine/eng_openssl.c crypto/engine/eng_table.c crypto/camellia/cmll_cbc.c
            crypto/engine/tb_dh.c
        )

        add_library(crypto STATIC ${crypto_SRCS})

        TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} crypto/ec/curve448/arch_32 crypto/include crypto/modes crypto crypto/ec/curve448 include)
        TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  OPENSSL_PIC ENGINESDIR="/usr/local/lib/engines-1.1" NDEBUG OPENSSL_USE_NODELETE OPENSSLDIR="/usr/local/ssl")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC  -pthread")
    endif() #arm64
elseif(WIN32)
    MESSAGE(FATAL_ERROR("Windows is not currently supported"))
elseif(UNIX)
    MESSAGE("Generating for Linux clang x86_64")

    set(arch "linux-x86_64-clang")
    find_program(PERL_EXECUTABLE perl)
    if(NOT PERL_EXECUTABLE)
        message(FATAL_ERROR("Perl not found"))
    endif(NOT PERL_EXECUTABLE)

    message("Configuring configdata.pm for \"${arch}\"")
    
    EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} Configure ${arch} 

            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE TEMP
            ERROR_VARIABLE ERROR
    )
    if(ERROR)
        MESSAGE(FATAL_ERROR("Error while configuring: ${ERROR}"))
    endif(ERROR)

    EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} util/mkbuildinf.pl "clang -fPIC -pthread -m64 -Wa,--noexecstack -Qunused-arguments -Wall -O3 -DOPENSSL_USE_NODELETE -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_CPUID_OBJ -DOPENSSL_IA32_SSE2 -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_MONT5 -DOPENSSL_BN_ASM_GF2m -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DKECCAK1600_ASM -DRC4_ASM -DMD5_ASM -DVPAES_ASM -DGHASH_ASM -DECP_NISTZ256_ASM -DX25519_ASM -DPOLY1305_ASM -DNDEBUG" ""linux-x86_64-clang"" 
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        OUTPUT_FILE crypto/buildinf.h
        ERROR_VARIABLE ERROR)
    if(ERROR)
        MESSAGE(FATAL_ERROR("Error while generating mkbuildinf: ${ERROR}"))
    endif(ERROR)

    foreach(el crypto/include/internal/bn_conf.h;crypto/include/internal/dso_conf.h;include/openssl/opensslconf.h)
        MESSAGE("Generating ${el}")
        EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE}
            "-I${CMAKE_CURRENT_LIST_DIR}" -Mconfigdata "util/dofile.pl" "-oMakefile" ${el}.in
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_FILE ${el}
            ERROR_VARIABLE error)
        if(error)
            message(FATAL_ERROR("Error while generating: ${error}"))
        endif(error)
    endforeach()
    
    set(PLs crypto/aes/asm/aesni-mb-x86_64.pl crypto/aes/asm/aesni-sha1-x86_64.pl crypto/aes/asm/aesni-sha256-x86_64.pl crypto/aes/asm/aesni-x86_64.pl crypto/aes/asm/vpaes-x86_64.pl crypto/bn/asm/rsaz-avx2.pl crypto/bn/asm/rsaz-x86_64.pl crypto/bn/asm/x86_64-gf2m.pl crypto/bn/asm/x86_64-mont.pl crypto/bn/asm/x86_64-mont5.pl crypto/camellia/asm/cmll-x86_64.pl crypto/chacha/asm/chacha-x86_64.pl crypto/ec/asm/ecp_nistz256-x86_64.pl crypto/ec/asm/x25519-x86_64.pl crypto/md5/asm/md5-x86_64.pl crypto/modes/asm/aesni-gcm-x86_64.pl crypto/modes/asm/ghash-x86_64.pl crypto/poly1305/asm/poly1305-x86_64.pl crypto/rc4/asm/rc4-md5-x86_64.pl crypto/rc4/asm/rc4-x86_64.pl crypto/sha/asm/keccak1600-x86_64.pl crypto/sha/asm/sha1-mb-x86_64.pl crypto/sha/asm/sha1-x86_64.pl crypto/sha/asm/sha256-mb-x86_64.pl crypto/sha/asm/sha512-x86_64.pl crypto/sha/asm/sha512-x86_64.pl crypto/whrlpool/asm/wp-x86_64.pl crypto/x86_64cpuid.pl engines/asm/e_padlock-x86_64.pl)
    set(ASMs crypto/aes/aesni-mb-x86_64.s crypto/aes/aesni-sha1-x86_64.s crypto/aes/aesni-sha256-x86_64.s crypto/aes/aesni-x86_64.s crypto/aes/vpaes-x86_64.s crypto/bn/rsaz-avx2.s crypto/bn/rsaz-x86_64.s crypto/bn/x86_64-gf2m.s crypto/bn/x86_64-mont.s crypto/bn/x86_64-mont5.s crypto/camellia/cmll-x86_64.s crypto/chacha/chacha-x86_64.s crypto/ec/ecp_nistz256-x86_64.s crypto/ec/x25519-x86_64.s crypto/md5/md5-x86_64.s crypto/modes/aesni-gcm-x86_64.s crypto/modes/ghash-x86_64.s crypto/poly1305/poly1305-x86_64.s crypto/rc4/rc4-md5-x86_64.s crypto/rc4/rc4-x86_64.s crypto/sha/keccak1600-x86_64.s crypto/sha/sha1-mb-x86_64.s crypto/sha/sha1-x86_64.s crypto/sha/sha256-mb-x86_64.s crypto/sha/sha256-x86_64.s crypto/sha/sha512-x86_64.s crypto/whrlpool/wp-x86_64.s crypto/x86_64cpuid.s engines/e_padlock-x86_64.s)
    list(LENGTH PLs _len)
    math(EXPR len "${_len}-1")
    foreach(idx RANGE ${len})

        list(GET PLs ${idx} pl)
        list(GET ASMs ${idx} asm)
        MESSAGE("Running \"${pl}\" to get \"${asm}\"")
        EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE}
            ${pl} elf ${asm}
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE temp
            ERROR_VARIABLE error
        )
        if(error)
            message(FATAL_ERROR("Error while generating: ${error}"))
        endif(error)
    endforeach()
        
    SET(ssl_SRCS
        ${COMMON_ssl_SRCS}
        
    )

    add_library(ssl STATIC ${ssl_SRCS})

    TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
    TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  ECP_NISTZ256_ASM SHA1_ASM POLY1305_ASM GHASH_ASM ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSL_BN_ASM_MONT5 VPAES_ASM KECCAK1600_ASM L_ENDIAN X25519_ASM NDEBUG OPENSSLDIR="/usr/local/ssl" RC4_ASM MD5_ASM SHA256_ASM OPENSSL_IA32_SSE2 OPENSSL_PIC OPENSSL_BN_ASM_MONT OPENSSL_BN_ASM_GF2m SHA512_ASM OPENSSL_CPUID_OBJ OPENSSL_USE_NODELETE)
    TARGET_COMPILE_OPTIONS(ssl PRIVATE  -pthread -m64 -Wa,--noexecstack -Qunused-arguments -fPIC)
    
    SET(crypto_SRCS
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

    TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE crypto/include include ${CMAKE_CURRENT_SOURCE_DIR} crypto crypto/ec/curve448 crypto/modes crypto/ec/curve448/arch_32)
    TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  ECP_NISTZ256_ASM SHA1_ASM POLY1305_ASM GHASH_ASM ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSL_BN_ASM_MONT5 VPAES_ASM KECCAK1600_ASM L_ENDIAN X25519_ASM NDEBUG OPENSSLDIR="/usr/local/ssl" RC4_ASM MD5_ASM SHA256_ASM OPENSSL_IA32_SSE2 OPENSSL_PIC OPENSSL_BN_ASM_MONT OPENSSL_BN_ASM_GF2m SHA512_ASM OPENSSL_CPUID_OBJ OPENSSL_USE_NODELETE)
    TARGET_COMPILE_OPTIONS(crypto PRIVATE  -pthread -m64 -Wa,--noexecstack -Qunused-arguments -fPIC)
        
elseif("iossimulator-xcrun")
    set(arch "iossimulator-xcrun")
    find_program(PERL_EXECUTABLE perl)
    if(NOT PERL_EXECUTABLE)
        message(FATAL_ERROR("Perl not found"))
    endif(NOT PERL_EXECUTABLE)

    message("Configuring configdata.pm for \"${arch}\"")
    
    EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} Configure ${arch} 

            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE TEMP
            ERROR_VARIABLE ERROR
    )
    if(ERROR)
        MESSAGE(FATAL_ERROR("Error while configuring: ${ERROR}"))
    endif(ERROR)

    EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} util/mkbuildinf.pl "clang -fPIC -arch arm64 -mios-version-min=7.0.0 -fno-common -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer//SDKs/iPhoneOS.sdk -O3 -DOPENSSL_PIC -D_REENTRANT -DNDEBUG" ""ios64-cross"" 
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        OUTPUT_FILE crypto/buildinf.h
        ERROR_VARIABLE ERROR)
    if(ERROR)
        MESSAGE(FATAL_ERROR("Error while generating mkbuildinf: ${ERROR}"))
    endif(ERROR)

    foreach(el crypto/include/internal/bn_conf.h;crypto/include/internal/dso_conf.h;include/openssl/opensslconf.h)
        MESSAGE("Generating ${el}")
        EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE}
            "-I${CMAKE_CURRENT_LIST_DIR}" -Mconfigdata "util/dofile.pl" "-oMakefile" ${el}.in
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_FILE ${el}
            ERROR_VARIABLE error)
        if(error)
            message(FATAL_ERROR("Error while generating: ${error}"))
        endif(error)
    endforeach()
    
    SET(ssl_SRCS
        ${COMMON_ssl_SRCS}
        
    )

    add_library(ssl STATIC ${ssl_SRCS})

    TARGET_INCLUDE_DIRECTORIES(ssl PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR})
    TARGET_COMPILE_DEFINITIONS(ssl PRIVATE  NDEBUG _REENTRANT OPENSSLDIR="/usr/local/ssl" ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSL_PIC)
    TARGET_COMPILE_OPTIONS(ssl PRIVATE -fno-common  -fPIC -mios-version-min=7.0.0)
    
    SET(crypto_SRCS
        ${COMMON_crypto_SRCS}
        crypto/rc4/rc4_enc.c crypto/des/des_enc.c crypto/camellia/camellia.c
        crypto/des/fcrypt_b.c crypto/rc4/rc4_skey.c crypto/whrlpool/wp_block.c
        crypto/camellia/cmll_misc.c crypto/chacha/chacha_enc.c crypto/bn/bn_asm.c
        crypto/sha/keccak1600.c crypto/bf/bf_enc.c crypto/mem_clr.c
        crypto/camellia/cmll_cbc.c crypto/aes/aes_core.c
    )

    add_library(crypto STATIC ${crypto_SRCS})

    TARGET_INCLUDE_DIRECTORIES(crypto PRIVATE crypto crypto/include crypto/modes crypto/ec/curve448/arch_32 include ${CMAKE_CURRENT_SOURCE_DIR} crypto/ec/curve448)
    TARGET_COMPILE_DEFINITIONS(crypto PRIVATE  NDEBUG _REENTRANT OPENSSLDIR="/usr/local/ssl" ENGINESDIR="/usr/local/lib/engines-1.1" OPENSSL_PIC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-common -mios-version-min=7.0.0 -fPIC ")
endif()

